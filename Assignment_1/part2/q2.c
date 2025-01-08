#include <stdio.h>
int main() {
FILE *file = fopen("example.txt", "w");
if (file) {
fprintf(file, "Hello, World!\n");
fclose(file);
} else {
printf("Error opening file.\n");
}
return 0;
}