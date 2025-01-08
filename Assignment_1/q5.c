#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main() {
pid_t pid = fork();
if (pid == 0) {
printf("Child process.\n");
} else {
wait(NULL);
printf("Child process finished.\n");
}
return 0;
