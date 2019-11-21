#include <stdio.h>
#include <math.h>

int arr[246913];
int main() {
    int n, a, b, sqrt_of_2n, count;
    scanf("%d", &n);

    while(n != 0) {
        sqrt_of_2n= (int)sqrt((double)(2 * n));
        count = n;
        arr[1] = n;

        for(a = 2; a <= sqrt_of_2n  ; ++a) {
            if(arr[a] == n)
                continue;

            for(b = a + a; b <= 2*n; b += a) {
                if(b > n && arr[b] != n)
                    --count;

                arr[b] = n;
            }
        }

        printf("%d\n", count);
        scanf("%d", &n);
    }
}