#include <stdio.h>
#include <math.h>

int main() {
    int number_of_testcase; // 테스트 케이스의 개수
    int count_testcase; // 테스트 케이스 카운트
    long long point_of_x, point_of_y; // 지점(Point)
    long long length; // x, y 사이의 거리
    long long sqrt_of_length; // 거리의 제곱근 값을 정수로 형변환하기 위한 값
    long long value_of_square; // square_of_length 의 제곱 값
    long long value_of_next_square; // square_of_length + 1의 제곱 값

    scanf("%d", &number_of_testcase);

    for(count_testcase = 0; count_testcase < number_of_testcase; ++count_testcase) {
        scanf("%lld %lld", &point_of_x, &point_of_y);

        length = point_of_y - point_of_x;
        sqrt_of_length = (int) sqrt((double)length);
        value_of_square = sqrt_of_length * sqrt_of_length;



        if(length == value_of_square) {
            // 제곱 수인 경우
            printf("%lld\n", (2 * sqrt_of_length) - 1);
            continue;
        } else {
            value_of_next_square = (sqrt_of_length + 1) * (sqrt_of_length + 1);
            if(length > (value_of_square + value_of_next_square) / 2) // 중간 값보다 큰 경우
                printf("%lld\n", 2 * sqrt_of_length + 1);
            else // 중간 값보다 작은 경우
                printf("%lld\n", 2 * sqrt_of_length);
        }
    }

    return 0;
}
