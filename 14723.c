#include <stdio.h>

int main() {
    int current_plus_value = 0, current_max_value = 0, prev_max_value = 0, number;
    scanf("%d", &number);
    do {
        ++current_plus_value;
        prev_max_value = current_max_value;
        current_max_value += current_plus_value;
    } while(current_max_value < number);

    printf("%d %d", ((current_plus_value + 1) - (number - prev_max_value)), (number - prev_max_value));
    return 0;
}