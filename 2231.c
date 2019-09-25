#include <stdio.h>

int main() {
    int input_number;
    scanf("%d", &input_number);
    int index = 0, calc_temp;
    while(index < input_number) {
        int current_number = index;
        calc_temp = current_number;
        calc_temp += current_number % 10;
        while(current_number /= 10) {
            calc_temp += current_number % 10;
        }

        if(calc_temp == input_number) {
            printf("%d", index);
            return 0;
        }
        ++index;
    }

    printf("%d", 0);
    return 0;
}