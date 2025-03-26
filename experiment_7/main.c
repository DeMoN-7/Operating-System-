#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// FIFO Page Replacement
void fifo(int frames, int pages, int pageSeq[]) {
    int frameArr[MAX_FRAMES];  // Frame array
    int pageFaults = 0, hits = 0, index = 0;

    // Frames ko -1 se initialize karna hai
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
    }

    printf("FIFO:\n");

    for (int i = 0; i < pages; i++) {
        int page = pageSeq[i], found = 0;

        // Check agar page frame me already hai
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = 1;
                hits++;
                break;
            }
        }

        // Agar nahi mila toh replace karo FIFO logic se
        if (!found) {
            frameArr[index] = page;         // Page ko replace 
            index = (index + 1) % frames;  // Index ko circular update 
            pageFaults++;
        }

        // Frame ka status print 
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] != -1)
                printf("|%d", frameArr[j]);
            else
                printf("| ");
        }
        printf("|%c\n", found ? 'H' : 'F');  // Hit/Fault status print 
    }

    printf("No. of Page Faults: %d\n", pageFaults);
    printf("No. of Hits: %d\n\n", hits);
}

// Main function
int main() {
    int frames, pages, pageSeq[MAX_PAGES];

    // File ko open karo
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: input.txt nahi khul pa raha!\n");
        return 1;
    }

    // Input file se read karo
    fscanf(file, "%d", &frames);  // Frames count
    fscanf(file, "%d", &pages);   // Pages count

    for (int i = 0; i < pages; i++) {
        fscanf(file, "%d", &pageSeq[i]);  // Page sequence read 
    }

    fclose(file);  


    fifo(frames, pages, pageSeq);

    // optimal(frames, pages, pageSeq);
    // lru(frames, pages, pageSeq);

    return 0;
}
