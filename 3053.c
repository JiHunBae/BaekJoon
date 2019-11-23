#include <stdio.h>
#include <math.h>

int main() {
    const double pi = acos(-1.0);
    int r;
    scanf("%d",&r);
    printf("%.6f\n%.6f",pi * r * r,2.0*r*r);
}