#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second) {
    return *(int *)first - *(int *)second;
}

int main() {
    int numbers[8001] = { 0 }; // 0 ~ 3999까지는 -(minus)값, 4000~8000까지는 0~4000값
    int number_of_inputs, input, count, accumulated_count = 0;
    int sum = 0, most_appear_value, most_appear_count = 0, mid_value = 9000, average, max_value = -8000, min_value = 8000, range, check = 0;

    scanf("%d", &number_of_inputs);

    for(count = 0; count < number_of_inputs; ++count) {
        scanf("%d", &input);
        sum += input;
        input += 4000; // 4000을 더한 값으로 계산 진행
        ++numbers[input];

        if(input > max_value)
            max_value = input;
        if(input < min_value)
            min_value = input;
    }


    for(count = min_value; count <= max_value; ++count) {
        if(numbers[count] != 0) {
            accumulated_count += numbers[count];
            if(numbers[count] > most_appear_count) {
                most_appear_value = count - 4000;
                most_appear_count = numbers[count];
                check = 1;
            } else if(numbers[count] == most_appear_count && check == 1) {
                most_appear_value = count - 4000;
                check = 2; // 두 번째로 작은 수로 변경되었으니 다른 최빈값이 나오기 전까지 이 조건문 진입 불가
            }

            if(mid_value == 9000 && accumulated_count >=  number_of_inputs/ 2 + 1)
                mid_value = count - 4000;
        }
    }
    if(sum >= 0)
        (((double)sum / (double) number_of_inputs) - (sum / number_of_inputs) >= 0.5) ? (average = (sum / number_of_inputs) + 1) : (average = sum / number_of_inputs);
    else
        (((double)sum / (double) number_of_inputs) - (sum / number_of_inputs) > -0.5) ? (average = (sum / number_of_inputs)) : (average = (sum / number_of_inputs) - 1);

    range = max_value - min_value;
    printf("%d\n%d\n%d\n%d\n", average, mid_value, most_appear_value, range);

    return 0;
}