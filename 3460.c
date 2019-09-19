#include <stdio.h>

int main() {
    int number_of_test, number, index, test_count = 0;
    int a,b;
    scanf("%d", &number_of_test);

    while(test_count < number_of_test) {
        scanf("%d", &number);
        index = 0;
        while(number > 0) {
            if(number % 2 == 1) printf("%d ", index);
            number/=2;
            ++index;
        }
        ++test_count;
    }
    return 0;
}