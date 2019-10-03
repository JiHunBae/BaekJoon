#include <stdio.h>

int main() {
    int numbers[10] = { 0 };
    int input, index;
    scanf("%d", &input);

    while((input / 10) > 0) {
        ++numbers[input % 10];
        input /= 10;
    }

    ++numbers[input];

    for(index = 9; index >= 0; --index) {
        while(numbers[index] > 0) {
            printf("%d", index);
            --numbers[index];
        }
    }

    return 0;
}