#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char message[100];
    char response[100];

    mkfifo("myfifo", 0666);

    printf("Server is waiting...\n");

    int fd = open("myfifo", O_RDONLY);

    read(fd, message, sizeof(message));
    printf("Client: %s", message);

    close(fd);

    printf("Enter response: ");
    fgets(response, sizeof(response), stdin);

    fd = open("myfifo", O_WRONLY);
    write(fd, response, strlen(response) + 1);

    close(fd);
    unlink("myfifo");

    return 0;
}
