#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void handle_signal(int sig) {
printf("Received signal %d\n", sig);
}
int main() {
signal(SIGTERM, handle_signal);
printf("Waiting for signal SIGTERM...\n");
pause();
return 0;
}