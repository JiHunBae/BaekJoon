#include <stdio.h>

#define MIN(x,y) ((x) < (y) ? (x): (y))

int find_max_square_value(int value);

int main() {
    int input_value; // 입력받은 수
    scanf("%d", &input_value);
    int value_for_square; // 제곱을 반복해가기 위해 필요한 수
    int value_for_max_square; // 제곱을 할 수 있는 수 중에서 가장 큰 수
    int index; // 어느 수를 가리키기위한 배열의 index값
    int dp[100001] = { 0 };
    dp[1] = 1;

    for(index = 2; index <= input_value; ++index) {
        value_for_max_square = find_max_square_value(index);
        dp[index] = dp[index - 1] + 1;
        for(value_for_square = 2; value_for_square <= value_for_max_square; ++value_for_square) {
            dp[index] = MIN(dp[index], dp[index - (value_for_square * value_for_square)] + 1);
        }
    }

    printf("%d", dp[input_value]);
}

int find_max_square_value(int value) {
    int square_result = 1;
    int square_value = 1;
    int result = 0;
    while(square_result <= value) {
        ++square_value;
        square_result = square_value * square_value;
        ++result;
    }

    return result;
}