#include <iostream>
using namespace std;

int main() {
    int t[20], d[20], h, n, temp, k, atr[20], tot, p, sum = 0;

    cout << "Enter the number of tracks to be traversed: ";
    cin >> n;

    cout << "Enter the position of the head: ";
    cin >> h;

    t[0] = 0;
    t[1] = h;

    cout << "Enter the total tracks: ";
    cin >> tot;

    t[2] = tot - 1;

    cout << "Enter the tracks:" << endl;
    for (int i = 3; i <= n + 2; i++)
        cin >> t[i];

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
                if (atr[j] > atr[j + 1])
                    d[j] = atr[j] - atr[j + 1];
                else
                    d[j] = atr[j + 1] - atr[j];
                sum += d[j];
            }
            cout << "Total header movements: " << sum << endl;
            cout << "Average is: " << static_cast<float>(sum) / n << endl;
        }
    }
    return 0;
}
