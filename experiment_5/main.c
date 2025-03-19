#include <stdio.h>

int main() {
    int n, m, i, j, k;
    // Input lene wale variables
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int total[m];
    printf("Enter number of instances of each resource: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &total[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int alloc[n][m], max[n][m], avail[m];
    printf("Enter allocation and max need for each process:\n");

    // Allocation and Max input le rhe hain
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Available resources calculate kar rhe hain
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] = total[j] - sum;
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;  // Process abhi tak complete nahi hua
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {  // Agar process complete nahi hua
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;  // Process complete ho gya
                }
            }
        }
    }

    // Check kar rahe hain sab processes complete hue ya nahi
    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The system is not in a safe state\n");
            break;
        }
    }

    if (flag == 1) {
        printf("Safe sequence is: ");
        for (i = 0; i < n - 1; i++) {
            printf("P%d, ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
