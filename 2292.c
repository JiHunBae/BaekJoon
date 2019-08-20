#include <stdio.h>

int main() {
    int input_value;
    scanf("%d", &input_value);

    int length = 1; // 1 까지의 거리
    int current_max = 1; // 1로 부터 동일한 거리의 값 중에서 가장 큰 값
    int add_value = 0; // 거리 1이 멀어지기 위해 더해주는 값
    int add_term = 6; // 더해주는 값이 6만큼 증가하므로 그 것을 위한 값


    while(input_value > current_max) {
        add_value += add_term;
        current_max += add_value;
        ++length;
    }

    printf("%d", length);
}