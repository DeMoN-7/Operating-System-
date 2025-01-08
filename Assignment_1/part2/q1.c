#include <stdio.h>
int main() {
FILE *file = fopen("example.txt", "r");
char line[100];
if (file) {
while (fgets(line, sizeof(line), file)) {
printf("%s", line);
}
fclose(file);
} else {
printf("Error opening file.\n");
}
return 0;
}
