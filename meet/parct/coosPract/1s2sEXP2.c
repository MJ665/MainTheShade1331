#include <stdio.h>
#include <string.h>

// Returns '0' for '1' and '1' for '0'
char flip(char c) {
    return (c == '0') ? '1' : '0';
}

// Print 1's and 2's complement of binary number
// represented by "bin"
void printOneAndTwosComplement(const char *bin) {
    int n = strlen(bin);
    int i;

    char ones[n + 1], twos[n + 1];
    ones[0] = twos[0] = '\0';

    // for ones complement flip every bit
    for (i = 0; i < n; i++) {
        ones[i] = flip(bin[i]);
    }
    ones[n] = '\0';

    // for two's complement go from right to left in
    // ones complement and if we get 1 make, we make
    // them 0 and keep going left when we get first
    // 0, make that 1 and go out of loop
    strcpy(twos, ones);
    for (i = n - 1; i >= 0; i--) {
        if (ones[i] == '1') {
            twos[i] = '0';
        } else {
            twos[i] = '1';
            break;
        }
    }

    // If No break: all are 1 as in 111 or 11111;
    // in such case, add extra 1 at the beginning
    if (i == -1) {
        char temp[n + 2];
        temp[0] = '1';
        strcpy(temp + 1, twos);
        strcpy(twos, temp);
    }

    printf("1's complement: %s\n", ones);
    printf("2's complement: %s\n", twos);
}

// Driver program
int main() {
    const char *bin = "1100";
    printOneAndTwosComplement(bin);
    // Output:
    // 1's complement: 0011
    // 2's complement: 0100
    return 0;
}