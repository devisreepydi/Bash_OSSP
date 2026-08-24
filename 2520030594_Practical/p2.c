#include <fcntl.h>
#include <unistd.h>
int main()
{
int f1, f2, n;
char buf[100];
f1 = open("t20", O_RDONLY);
f2 = open("t21", O_WRONLY | O_CREAT, 0644);
n = read(f1, buf, 100);
write(f2, buf, n);
close(f1);
close(f2);
return 0;
}
