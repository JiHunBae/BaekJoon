#include <stdio.h>
#include <math.h>

int main() {
    int arr[10001];
    int t, n, a, b, sqrt_of_n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        sqrt_of_n = (int) sqrt((double) n);
        arr[1] = n;
        for (a = 2; a <= sqrt_of_n; ++a) {
            if (arr[a] == n)
                continue;
            for (b = a << 1; b <= n; b += a)
                arr[b] = n;
        }
        for (a = n >> 1; a <= n - 2; ++a) {
            if (arr[a] != n && arr[n-a] != n) {
                printf("%d %d\n", n-a, a);
                break;
            }
        }

    }
}