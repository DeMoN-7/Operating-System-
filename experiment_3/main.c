#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
# define bufferSize 100
int main(){
    int buf1[2],buf2[2];
    pid_t pid; // child proccess create krne ke liye
    char input_str[bufferSize], reversed_str[bufferSize];

    // Create pipes
    // also chk if pid smaller thn 0 it means pipe nto created

    if (pipe(buf1) == -1 || pipe(buf2) == -1) {
        perror("Pipe failed");
        return 1;
    }
     pid = fork();  // Create child process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    
    if (pid == 0) {  // Child process
        close(buf1[1]);  // Close write end of buffer1
        close(buf2[0]);  // Close read end of buffer2

        // Read input from parent
        read(buf1[0], input_str, bufferSize);
        close(buf1[0]);

         int len = strlen(input_str);
        for (int i = 0; i < len; i++) {
            reversed_str[i] = input_str[len - i - 1];
        }
        reversed_str[len] = '\0';

         write(buf2[1], reversed_str, bufferSize);
        close(buf2[1]);
        }
        else {  // Parent process
        close(buf1[0]);  // Close read end of buffer1
        close(buf2[1]);  // Close write end of buffer2

        // =taking input from the user
        printf("Enter a string ");
        fgets(input_str, bufferSize, stdin);
    
        // Write input to child
        write(buf1[1], input_str, bufferSize);
        close(buf1[1]);
        wait(NULL);

        // Read reversed string from child
        read(buf2[0], reversed_str, bufferSize);
        close(buf2[0]);

        // Print the reversed string
        printf("Reversed string: %s\n", reversed_str);
    }

    return 0;

}