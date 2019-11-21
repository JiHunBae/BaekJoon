#include <stdio.h>

int x[51], y[51], rank[51];

int main() {
    int n, i, j, count;
    i = 1;
    scanf("%d",&n);
    for(i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    for(i = 1; i <= n; ++i) {
        count = 1;
        for(j = 1; j <= n; ++j) {
            if(x[i] < x[j] && y[i] < y[j])
                ++count;
        }
        rank[i] = count;
    }
    for(i = 1; i <= n; ++i)
        printf("%d ", rank[i]);
}