#include <stdio.h>

int main() {
    long long a,b,c, total_cost, total_income;
    long long count;
    scanf("%lld %lld %lld", &a, &b, &c);

    total_cost = a;
    total_income = 0;
    // A + x * B < x * C  -> x???
    if(b >= c) {
        printf("%d", -1);
    } else {
        printf("%lld", (a / (c - b)) + 1);
    }

    return 0;
}