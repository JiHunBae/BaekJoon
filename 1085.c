#include <stdio.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main() {
    int x,y,w,h, min;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    min = MIN(x, w-x);
    min = MIN(min, y);
    min = MIN(min, h-y);
    printf("%d", min);
}