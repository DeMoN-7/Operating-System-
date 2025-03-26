#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// First Fit Allocation Function
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Pehle sabko -1, yani koi allocate nahi hua
    }

    // Har process ke liye block dhundh rahe hain
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) { // Agar block process se bada ya barabar hai
                allocation[i] = j; // Process ko allocate kar diya
                blockSize[j] -= processSize[i]; // Block size ko kam kiya
                break;
            }
        }
    }

    // Output ko print kar rahe hain
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("P%d -> Block %d (Size %d)\n", i + 1, allocation[i] + 1, processSize[i]);
        else
            printf("P%d -> Not Allocated\n", i + 1);
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r"); // File ko read mode me open kiya

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int m, n;
    int blockSize[MAX], processSize[MAX];

    // Partition ka size read kar rahe hain
    fscanf(file, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &blockSize[i]);
    }

    // Process ka size read kar rahe hain
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &processSize[i]);
    }

    fclose(file); // File ko close kar diya

    // First Fit function ko call kar rahe hain
    firstFit(blockSize, m, processSize, n);

    return 0;
}
