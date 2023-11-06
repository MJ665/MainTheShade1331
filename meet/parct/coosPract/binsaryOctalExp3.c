#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinaryNumbers(const char* a, const char* b) {
    int max_len = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
    char* result = (char*)malloc((max_len + 2) * sizeof(char));
    int carry = 0;
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;

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

        result[k] = '0' + (sum % 2);
        carry = sum / 2;
        k++;
    }

    if (carry != 0) {
        result[k] = '0' + carry;
        k++;
    }

    result[k] = '\0';
    // Reverse the result
    int start = 0;
    int end = k - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

int main() {
    char a[100], b[100];
    printf("Enter the first binary number: ");
    scanf("%s", a);
    printf("Enter the second binary number: ");
    scanf("%s", b);

    char* result = addBinaryNumbers(a, b);
    printf("The sum is: %s\n", result);

    free(result); // Don't forget to free the dynamically allocated memory
    // Output
    // Enter the first binary number: 1011
    // Enter the second binary number: 1101 
    // The sum is: 11000
    return 0;
}