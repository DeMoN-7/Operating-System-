#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// First Fit Allocation
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Process abhi allocate nahi hua
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Memory consume ho gayi
                break;
            }
        }
    }

    printf("\nFirst Fit:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("P%d %d\n", i + 1, processSize[i]);
        else
            printf("P%d Not Allocated\n", i + 1);
    }
}

// Best Fit Allocation
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j; // Sabse choti suitable block choose kar rahe hain
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("P%d %d\n", i + 1, processSize[i]);
        else
            printf("P%d Not Allocated\n", i + 1);
    }
}

// Worst Fit Allocation
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j; // Sabse badi block allocate kar rahe hain
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nWorst Fit:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("P%d %d\n", i + 1, processSize[i]);
        else
            printf("P%d Not Allocated\n", i + 1);
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r"); // File se input le rahe hain

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int m, n;
    int blockSize[MAX], processSize[MAX];

    fscanf(file, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &blockSize[i]);
    }

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &processSize[i]);
    }

    fclose(file); // File band kar di

    // Block sizes ko alag-alag copy kar rahe hain har method ke liye
    int blockSize1[MAX], blockSize2[MAX], blockSize3[MAX];
    for (int i = 0; i < m; i++) {
        blockSize1[i] = blockSize[i];
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }

    firstFit(blockSize1, m, processSize, n);
    bestFit(blockSize2, m, processSize, n);
    worstFit(blockSize3, m, processSize, n);

    return 0;
}
