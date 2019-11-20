#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int arr[1000001];
int main() {
    int i, j, m, n, sqrt_of_n;
    scanf("%d %d", &m, &n);
    sqrt_of_n = (int)sqrt((double)n);
    arr[1] = 1;

    for(i = 2; i <= sqrt_of_n; ++i) {
        if(arr[i] == 1)
            continue;

        for(j = i + i; j <= n; j += i)
            arr[j] = 1;
    }

    for(i = m; i <= n; ++i) {
        if(arr[i] != 1)
            printf("%d\n", i);
    }
}