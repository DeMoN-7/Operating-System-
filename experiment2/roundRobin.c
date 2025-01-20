#include <stdio.h>
#define MAX 100
int main() {
    int n, pid[MAX], arrival[MAX], burst[MAX], remaining[MAX];
    int completion[MAX] = {0}, turnaround[MAX], waiting[MAX], response[MAX] = {-1};
    int quantum = 2, current_time = 0, completed = 0;
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d %d", &pid[i], &arrival[i], &burst[i]);
        remaining[i] = burst[i];
    }
    fclose(file);
    printf("\nGantt Chart:\n|");
    while (completed < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= current_time && remaining[i] > 0) {
                found = 1;
                if (response[i] == -1) response[i] = current_time - arrival[i];
                if (remaining[i] <= quantum) {
                    printf(" P%d(%d) ", pid[i], current_time);
                    current_time += remaining[i];
                    remaining[i] = 0;
                    completion[i] = current_time;
                    completed++;
                } else {
                    printf(" P%d(%d) ", pid[i], current_time);
                    current_time += quantum;
                    remaining[i] -= quantum;
                }
            }
        }
        if (!found) current_time++;
    }
    printf("|\n");
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", pid[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i], response[i]);
    }
    return 0;
}
