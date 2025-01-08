#include <stdio.h>
int main() {
FILE *file = fopen("newfile.txt", "w");
if (file) {
printf("File created successfully.\n");
fclose(file);
} else {
printf("Error creating file.\n");
}
return 0;
}
