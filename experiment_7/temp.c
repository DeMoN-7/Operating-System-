#include <stdio.h>
#include <stdlib.h>

#define max_frame 100
#define max_pages 100

void fifo(int frames, int pages, int pageSeq[])
{
    int frameArr[max_frame] = {-1};  // Frames ko empty initialize kiya
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

int main()
{
    int frames, pages, pageSeq[max_pages];

    // Input lena
    printf("Enter frames and pages:\n");
    scanf("%d", &frames);   // Frames count
    scanf("%d", &pages);    // Pages count
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageSeq[i]);
    }

    // FIFO ko call karo
    fifo(frames, pages, pageSeq);
    return 0;
}