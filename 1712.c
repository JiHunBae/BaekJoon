#include <stdio.h>

int main() {
    long long a,b,c, total_cost, total_income;
    long long count;
    scanf("%lld %lld %lld", &a, &b, &c);

    total_cost = a;
    total_income = 0;
    // A + x * B < x * C  -> x???
    if(b > c) {
        printf("%d", -1);
        return 0;
    }

    for(count = 1; count <= 2100000000; ++count) {
        total_cost += b;
        total_income += c;
        if(total_income > total_cost) {
            printf("%lld", count);
            break;
        }
    }

    return 0;
}