#include <iostream>
using namespace std;

int main() {
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;

    cout << "Enter the number of tracks: ";
    cin >> n;

    cout << "Enter the tracks to be traversed: ";
    for (i = 2; i < n + 2; i++)
        cin >> t[i];

    for (i = 1; i < n + 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = tohm[i] * (-1);
    }

    for (i = 1; i < n + 1; i++)
        tot += tohm[i];

    avhm = static_cast<float>(tot) / n;

    cout << "Tracks traversed\t\tDifference between tracks" << endl;
    for (i = 1; i < n + 1; i++)
        cout << t[i] << "\t\t\t\t\t\t\t\t" << tohm[i] << endl;

    cout << "\nAverage header movements: " << avhm << endl;

    return 0;
}
