#include <stdio.h>
#define MAX 100
int main() {
    int n, pid[MAX], arrival[MAX], burst[MAX], priority[MAX];
    int start[MAX], completion[MAX], turnaround[MAX], waiting[MAX], response[MAX];
    int completed[MAX] = {0}, current_time = 0, completed_count = 0;
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d %d %d", &pid[i], &arrival[i], &burst[i], &priority[i]);
    }
    fclose(file);
    printf("\nGantt Chart:\n");
    while (completed_count < n) {
        int idx = -1, min_priority = 1000000;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= current_time && !completed[i] && priority[i] < min_priority) {
                min_priority = priority[i];
                idx = i;
            }
        }
        if (idx != -1) {
            start[idx] = current_time;
            completion[idx] = current_time + burst[idx];
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            response[idx] = start[idx] - arrival[idx];
            current_time = completion[idx];
            completed[idx] = 1;
            completed_count++;
            printf("| P%d (%d) ", pid[idx], start[idx]);
        } else {
            current_time++;
        }
    }
    printf("|\n");

    printf("\nPID\tArrival\tBurst\tPriority\tStart\tCompletion\tTurnaround\tWaiting\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t%d\n", pid[i], arrival[i], burst[i], priority[i], start[i], completion[i], turnaround[i], waiting[i], response[i]);
    }
    return 0;
}
