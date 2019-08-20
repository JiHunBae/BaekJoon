#include <stdio.h>
typedef enum {false, true} bool;
int main() {
    int input_value;
    int minus_value = 1;
    int minus_term = 1;
    int numerator, denominator; // 순서대로 분자, 분모
    scanf("%d", &input_value);
    bool numerator_bigger_than_denominator = false; // 꺾이는 지점에서 분자가 분모보다 큰 값인지 확인
    int sum_value = 1; // 분자와 분모의 합

    while(input_value > 0) {
        input_value -= minus_value;
        minus_value += minus_term;
        ++sum_value;

        if(numerator_bigger_than_denominator)
            numerator_bigger_than_denominator = false;
        else
            numerator_bigger_than_denominator = true;
    }

    input_value *= -1; // 뺄셈으로 인해서 차이값이 지그재그 지점으로부터의 거리 차이가 음수가 되므로 -1을 곱해줌
    if(numerator_bigger_than_denominator) {
        numerator = input_value + 1;
        denominator = sum_value - numerator;


    } else {
        denominator = input_value + 1;
        numerator = sum_value - denominator;
    }

    printf("%d/%d", numerator, denominator);

    return 0;
}