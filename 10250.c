#include <stdio.h>

int main() {
    int number_of_testcase, count;
    int h, w, n;
    scanf("%d", &number_of_testcase);
    int y, x ,x1, x2;

    for(count = 0; count < number_of_testcase; ++count) {
        scanf("%d %d %d", &h, &w, &n);
        (n % h == 0) ? (y = h) : (y = n - (n / h) * h);
        (n % h == 0) ? (x = (n/h)) : (x = (n / h)+ 1);
        x1 = x / 10;
        x2 = x % 10;
        printf("%d%d%d\n", y,x1,x2);
    }

    return 0;
}