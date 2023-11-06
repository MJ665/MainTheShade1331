#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addOctalNumbers(const char* a, const char* b) {
    int max_len = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
    char* result = (char*)malloc((max_len + 2) * sizeof(char));
    int carry = 0;
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;

    a = strrev(strdup(a)); // Reverse the input strings
    b = strrev(strdup(b));

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result[k] = '0' + (sum % 8);
        carry = sum / 8;
        k++;
    }

    if (carry != 0) {
        result[k] = '0' + carry;
        k++;
    }

    result[k] = '\0';
    return strrev(result); // Reverse the result back to normal order
}

int main() {
    char a[100], b[100];
    printf("Enter the first octal number: ");
    scanf("%s", a);
    printf("Enter the second octal number: ");
    scanf("%s", b);

    char* result = addOctalNumbers(a, b);
    printf("The sum is: %s\n", result);

    free(result); // Don't forget to free the dynamically allocated memory

    return 0;
}