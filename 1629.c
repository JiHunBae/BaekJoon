#include <stdio.h>

long long get_division_rest_of_mul(long long num1, long long num2, long long num3);
int main() {
    long long  a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long result = get_division_rest_of_mul(a,b,c);
    printf("%d",result);
    return 0;
}

long long get_division_rest_of_mul(long long num1, long long num2, long long num3) {
    if (num2 > 1) {
        long long result;
        if(num2 % 2 == 0) {
            result = get_division_rest_of_mul(num1, (long long)num2/2, num3);
            result = (result * result) % num3;
        } else {
            result = get_division_rest_of_mul(num1, (long long)num2/2, num3);
            result = (result * result) % num3;
            result = (result * num1) % num3;
        }
        return result;
    } else if(num2 == 1)
        return num1 % num3;
}
