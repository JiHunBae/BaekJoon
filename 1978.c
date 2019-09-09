#include <stdio.h>

int check_prime_number(int number) {
    // 소수인지 판별해주는 함수, 소수이면 1, 아니면 0을 반환한다.

    if(number == 1)
        return 0;

    int number_of_checking = number - 1;
    int divisor;

    for(divisor = 2; divisor < number_of_checking; ++divisor) {
        if(number % divisor == 0)
            return 0;
    }

    return 1;
}

int main() {
    int number_of_sequences, number, count;
    int prime_number_count = 0;

    scanf("%d", &number_of_sequences);

    for(count = 0; count < number_of_sequences; ++count) {
        scanf("%d", &number);

        if(check_prime_number(number))
            ++prime_number_count;
    }

    printf("%d", prime_number_count);

    return 0;
}