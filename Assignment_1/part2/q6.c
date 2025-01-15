#include <stdio.h>
#include <string.h>
int main() {
FILE *file = fopen("example.txt", "r");
char line[100];
char *keyword = "Hello";
if (file) {
while (fgets(line, sizeof(line), file)) {
if (strstr(line, keyword)) {
printf("%s", line);
}
}
fclose(file);
} else {
printf("Error opening file.\n");
}
return 0;
}
