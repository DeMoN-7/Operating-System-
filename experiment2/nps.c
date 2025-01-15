// Turnaround Time=Completion Time−Arrival Time
// Waiting Time=Turnaround Time−Burst Time
// Response Time=Start Time−Arrival Time
#define MAX 100
#include<string.h>
#include<stdio.h>
void main(){
    FILE *file=fopen("input.txt");
    int pid[MAX], arrival_time[MAX], burst_time[MAX], priority[MAX];
    fscanf(file, "%d", &n);  
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d %d %d", &pid[i], &arrival_time[i], &burst_time[i], &priority[i]);
    }
    fclose(file);
        printf("%d %d %d %d", pid[i], arrival_time[i], burst_time[i], priority[i]);
    
}