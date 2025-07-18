#include <stdio.h>
#include <string.h>

// Function to perform bit stuffing
void bitStuffing(const char *input, char *output) {
    int count = 0;  // Count consecutive 1s
    int j = 0;      // Index for output

    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];

        if (input[i] == '1') {
            count++;
            if (count == 5) {
                // Insert a '0' after 5 consecutive '1's
                output[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;  // Reset count if bit is 0
        }
    }
    output[j] = '\0';  // Null-terminate the output string
}

int main() {
    char input[100], output[200];

    printf("Enter the bit stream (0s and 1s): ");
    scanf("%s", input);

    bitStuffing(input, output);

    printf("Bit stuffed output: %s\n", output);

    return 0;
}

