1.fork()
#include<stdio.h>
#include<unistd.h>
int main()
{
fork();
printf("hello how are you\n");
}

2.exce.c
  #include<unistd.h>
#include<stdio.h>
int main()
{
execl("/bin/ls", "ls", "-l", NULL);
execlp("pwd", "pwd", NULL);
char *args[] = {"ls", "-l", NULL};
execv("/bin/ls", args);
}

3.parent.c
  #include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid = fork();
if (pid == 0)
{
printf("Child PID: %d\n", getpid());
printf("Parent PID: %d\n", getppid());
}
else
{
printf("Parent PID: %d\n", getpid());
printf("Child PID: %d\n", pid);
}
return 0;
}
