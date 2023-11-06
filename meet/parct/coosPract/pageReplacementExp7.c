FIFO
1.	Start the process
2.	Read number of pages n
3.	Read number of pages no
4.	Read page numbers into an array a[i]
5.	Initialize avail[i]=0 .to check page hit
6.	Replace the page with circular queue, while re-placing check page availability in the frame Place avail[i]=1 if page is placed in the frame Count page faults
7. Print the results.
8. Stop the process.
#include <stdio.h>
int fr[3];
void display() {
    for (int i = 0; i < 3; i++) {
        printf("%d\t", fr[i]);
    }
    printf("\n");
}

int main() {
    int i, j;
    int page[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;

    // Initialize the frame array
    for (i = 0; i < 3; i++) {
        fr[i] = -1;
    }

    for (j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < 3; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            fr[top] = page[j];
            top++;
            pf++;
            if (top >= frsize) top = 0;
        }

        display();
    }
    printf("Number of page faults: %d\n", pf + frsize);
    // Output:
    // 2       -1      -1
    // 2       3       -1
    // 2       3       -1
    // 2       3       1 
    // 5       3       1 
    // 5       2       1 
    // 5       2       4 
    // 5       2       4 
    // 3       2       4 
    // 3       2       4
    // 3       5       4
    // 3       5       2
    // Number of page faults: 9
    return 0;
}



















LRU

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int pageFaults(int pages[], int n, int capacity) {
    int s[capacity];
    int indexes[capacity];
    int page_faults = 0;

    for (int i = 0; i < capacity; i++) {
        s[i] = -1;
        indexes[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bool page_found = false;
        int j;

        for (j = 0; j < capacity; j++) {
            if (s[j] == pages[i]) {
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            int lru = INT_MAX;
            int val = -1;

            for (j = 0; j < capacity; j++) {
                if (indexes[j] < lru) {
                    lru = indexes[j];
                    val = j;
                }
            }

            s[val] = pages[i];
            page_faults++;
        }

        indexes[j] = i;
    }

    return page_faults;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    printf("Number of page faults: %d\n", pageFaults(pages, n, capacity));
    // Output:
    // Number of page faults: 13
    return 0;
}























Optimal

1.	If the referred page is already present, increment hit count.
2.	If not present, find a page that is never referenced in future. If such a page exists, replace this page with a new page. If no such page exists, find a page that is referenced farthest in future. Replace this page with a new page.

#include <stdio.h>
#include <stdbool.h>

bool search(int key, int fr[], int fr_size) {
    for (int i = 0; i < fr_size; i++) {
        if (fr[i] == key) {
            return true;
        }
    }
    return false;
}

int predict(int pg[], int fr[], int pn, int index, int fr_size) {
    int res = -1;
    int farthest = index;

    for (int i = 0; i < fr_size; i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                    break;
                }
            }
            if (j == pn) {
                return i;
            }
        }
    }
    return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn) {
    int fr[fn];
    int hit = 0;

    for (int i = 0; i < pn; i++) {
        if (search(pg[i], fr, fn)) {
            hit++;
        } else {
            if (i >= fn) {
                int j = predict(pg, fr, pn, i + 1, fn);
                fr[j] = pg[i];
            } else {
                fr[i] = pg[i];
            }
        }
    }

    printf("No. of hits = %d\n", hit);
    printf("No. of misses = %d\n", pn - hit);
}

int main() {
    int pg[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;

    optimalPage(pg, pn, fn);

    return 0;
}




















