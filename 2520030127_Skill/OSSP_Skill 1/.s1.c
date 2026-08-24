#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    printf("Parent process started. PID = %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process created. PID = %d, PPID = %d\n",
               getpid(), getppid());

        execlp("ls", "ls", "-l", NULL);

        perror("exec failed");
        exit(1);
    }
    else
    {
        printf("Parent waiting for child. PID = %d\n", getpid());

        wait(NULL);

        printf("Child process completed.\n");
    }

    return 0;
}
