#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define REQUEST_FIFO "request_fifo"
#define RESPONSE_FIFO "response_fifo"

int main()
{
    char message[100];
    char response[150];

    mkfifo(REQUEST_FIFO, 0666);
    mkfifo(RESPONSE_FIFO, 0666);

    printf("Server started...\n");

    while (1)
    {
        int fd1 = open(REQUEST_FIFO, O_RDONLY);

        read(fd1, message, sizeof(message));
        close(fd1);

        printf("Client message: %s\n", message);

        sprintf(response, "Server processed: %s", message);

        int fd2 = open(RESPONSE_FIFO, O_WRONLY);

        write(fd2, response, strlen(response) + 1);
        close(fd2);

        printf("Response sent to client.\n");
    }

    return 0;
}
