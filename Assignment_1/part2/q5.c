#include <dirent.h>
#include <stdio.h>
int main() {
struct dirent *entry;
DIR *dir = opendir(".");
if (dir) {
while ((entry = readdir(dir)) != NULL) {
printf("%s\n", entry->d_name);
}
closedir(dir);
} else {
printf("Error opening directory.\n");
}
return 0;
}
