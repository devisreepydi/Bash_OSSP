1. shell.c
  #include <stdio.h>
#include <string.h>
int main()
{
char command[100];
while (1)
{
printf("myshell> ");
fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
break;
}
printf("You entered: %s\n", command);
}
return 0;
}


2.input.c
  #include <stdio.h>
#include <string.h>
int main()
{
char input[100];
while (1)
{
printf("myshell> ");
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0';
if (strcmp(input, "exit") == 0)
{
break;
}
printf("You entered: %s\n", input);
}
return 0;
}
