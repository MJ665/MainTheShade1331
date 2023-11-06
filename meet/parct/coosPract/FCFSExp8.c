FCFS



#include <stdio.h>

int main() {
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 1; i < n + 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0) {
            tohm[i] = tohm[i] * (-1);
        }
    }

    for (i = 1; i < n + 1; i++) {
        tot += tohm[i];
    }

    avhm = (float)tot / n;

    printf("Tracks traversed\t\tDifference between tracks\n");
    for (i = 1; i < n + 1; i++) {
        printf("%d\t\t\t\t\t\t\t\t%d\n", t[i], tohm[i]);
    }

    printf("\nAverage header movements: %f\n", avhm);

    return 0;
}










scanf


#include <stdio.h>
#include <stdlib.h>

#define size 8
#define disk_size 200

void SCAN(int arr[], int head, char* direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int seek_sequence[size * 2];
    int left_count = 0, right_count = 0;

    if (strcmp(direction, "left") == 0)
        left[left_count++] = 0;
    else if (strcmp(direction, "right") == 0)
        right[right_count++] = disk_size - 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    for (int run = 0; run < 2; run++) {
        if (strcmp(direction, "left") == 0) {
            for (int i = left_count - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[seek_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "right");
        } else if (strcmp(direction, "right") == 0) {
            for (int i = 0; i < right_count; i++) {
                cur_track = right[i];
                seek_sequence[seek_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "left");
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is:\n");
    for (int i = 0; i < seek_count; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

int main() {
    int arr[size] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    char direction[] = "left";
    SCAN(arr, head, direction);
    return 0;
}


















C Scan




#include <stdio.h>

int main() {
    int t[20], d[20], h, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);
    t[0] = 0;
    t[1] = h;

    printf("Enter the total tracks: ");
    scanf("%d", &tot);
    t[2] = tot - 1;

    printf("Enter the tracks:\n");
    for (int i = 3; i <= n + 2; i++) {
        scanf("%d", &t[i]);
    }

    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                // Swap t[j] and t[j+1]
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    int j = 0;
    for (int i = 0; i <= n + 2; i++) {
        if (t[i] == h) {
            temp = t[j];
            t[j] = t[j + 1];
            t[j + 1] = temp;
            p = 0;
            while (t[j] != tot - 1) {
                j = i;
                atr[p] = t[j];
                j++;
                p++;
            }
            atr[p] = t[j];
            p++;
            i = 0;
            while (p != (n + 3) && t[i] != t[h]) {
                atr[p] = t[i];
                i++;
                p++;
            }
            for (j = 0; j < n + 2; j++) {
                if (atr[j] > atr[j + 1]) {
                    d[j] = atr[j] - atr[j + 1];
                } else {
                    d[j] = atr[j + 1] - atr[j];
                }
                sum += d[j];
            }
            printf("Total header movements: %d\n", sum);
            printf("Average is: %f\n", (float)sum / n);
        }
    }

    return 0;
}












