#include <stdio.h>

int main() {
    long long first_Number, second_Number, result;
    scanf("%lld", &first_Number);
    scanf("%lld", &second_Number);

    long long bigger_Number, smaller_Number;
    bigger_Number = (first_Number > second_Number) ? first_Number:second_Number;
    smaller_Number = (first_Number > second_Number) ? second_Number:first_Number;
    result = (bigger_Number + smaller_Number) * (bigger_Number - smaller_Number + 1) / 2;
    printf("%d", result);
    return 0;
}