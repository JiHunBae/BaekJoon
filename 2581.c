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
    int numbers[10001] = { 0 };
    int start, end, index;
    int sum = 0, min = 0;

    for(index = 1; index < 10001; ++index) {
        numbers[index] = check_prime_number(index);
    }

    scanf("%d %d", &start, &end);

    for(index = start; index < end + 1; ++index) {
        if(numbers[index]) {
            if(min == 0)
                min = index;

            sum += index;
        }
    }

    (min == 0) ? printf("-1") : printf("%d\n%d\n", sum, min);

    return 0;
}