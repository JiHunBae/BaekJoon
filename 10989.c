#include <stdio.h>

int main() {
    int number_count[10001] = { 0 };
    int number_of_inputs, input, index;

    scanf("%d", &number_of_inputs);

    for(index = 0; index < number_of_inputs; ++index) {
        scanf("%d", &input);
        ++number_count[input];
    }

    for(index = 0; index < 10001; ++index) {
        while(number_count[index] != 0) {
            printf("%d\n", index);
            --number_count[index];
        }
    }

    return 0;
}