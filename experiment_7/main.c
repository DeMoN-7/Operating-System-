#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// FIFO Page Replacement
void fifo(int frames, int pages, int pageSeq[]) {
    int frameArr[MAX_FRAMES] = {-1};  // Frames ko empty initialize kiya
    int pageFaults = 0, hits = 0, index = 0;

    printf("FIFO:\n");

    for (int i = 0; i < pages; i++) {
        int page = pageSeq[i], found = 0;

        // Check kar rahe hai agar page already frame me hai
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = 1;
                hits++;
                break;
            }
        }

        // Agar nahi mila to replace karo FIFO se
        if (!found) {
            frameArr[index] = page;
            index = (index + 1) % frames;
            pageFaults++;
        }

        // Frame ka status print karo
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] != -1)
                printf("|%d", frameArr[j]);
            else
                printf("| ");
        }
        printf("|%c\n", found ? 'H' : 'F');
    }

    printf("No. of Page Faults: %d\n", pageFaults);
    printf("No. of Hits: %d\n\n", hits);
}

// Optimal Page Replacement (OPR)
void optimal(int frames, int pages, int pageSeq[]) {
    int frameArr[MAX_FRAMES] = {-1};
    int pageFaults = 0, hits = 0;

    printf("OPR:\n");

    for (int i = 0; i < pages; i++) {
        int page = pageSeq[i], found = 0;

        // Check agar page already frame me hai
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = 1;
                hits++;
                break;
            }
        }

        // Agar nahi mila to replace karo
        if (!found) {
            if (i < frames) {
                frameArr[i] = page;  // Pehle frames fill karo
            } else {
                int farthest = -1, replaceIndex = -1;

                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < pages; k++) {
                        if (frameArr[j] == pageSeq[k]) break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                frameArr[replaceIndex] = page;
            }
            pageFaults++;
        }

        // Frame ka status print karo
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] != -1)
                printf("|%d", frameArr[j]);
            else
                printf("| ");
        }
        printf("|%c\n", found ? 'H' : 'F');
    }

    printf("No. of Page Faults: %d\n", pageFaults);
    printf("No. of Hits: %d\n\n", hits);
}

// Least Recently Used (LRU) Page Replacement
void lru(int frames, int pages, int pageSeq[]) {
    int frameArr[MAX_FRAMES] = {-1};
    int pageFaults = 0, hits = 0;
    int lastUsed[MAX_FRAMES] = {0};  // Track last used position

    printf("LRU:\n");

    for (int i = 0; i < pages; i++) {
        int page = pageSeq[i], found = 0;

        // Check agar page already frame me hai
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = 1;
                hits++;
                lastUsed[j] = i;  // Update last used time
                break;
            }
        }

        // Agar nahi mila to replace karo
        if (!found) {
            int replaceIndex = 0;
            if (i < frames) {
                replaceIndex = i;
            } else {
                int lruIndex = 0, minTime = INT_MAX;
                for (int j = 0; j < frames; j++) {
                    if (lastUsed[j] < minTime) {
                        minTime = lastUsed[j];
                        lruIndex = j;
                    }
                }
                replaceIndex = lruIndex;
            }
            frameArr[replaceIndex] = page;
            lastUsed[replaceIndex] = i;
            pageFaults++;
        }

        // Frame ka status print karo
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] != -1)
                printf("|%d", frameArr[j]);
            else
                printf("| ");
        }
        printf("|%c\n", found ? 'H' : 'F');
    }

    printf("No. of Page Faults: %d\n", pageFaults);
    printf("No. of Hits: %d\n\n", hits);
}

// Main function
int main() {
    int frames, pages, pageSeq[MAX_PAGES];

    // Input lena
    scanf("%d", &frames);   // Frames count
    scanf("%d", &pages);    // Pages count
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageSeq[i]);
    }

    // FIFO ko call karo
    fifo(frames, pages, pageSeq);
    
    // Optimal ko call karo
    optimal(frames, pages, pageSeq);
    
    // LRU ko call karo
    lru(frames, pages, pageSeq);

    return 0;
}
