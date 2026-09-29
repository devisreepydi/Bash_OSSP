#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char message[100];
    char response[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    int fd = open("myfifo", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    fd = open("myfifo", O_RDONLY);

    read(fd, response, sizeof(response));

    printf("Server: %s", response);

    close(fd);

    return 0;
}
