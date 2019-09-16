#include <stdio.h>

int main() {
    int up_meter, down_meter, tree_height, current_height = 0, day = 0;
    scanf("%d%d%d", &up_meter, &down_meter, &tree_height);
    ++day, tree_height -= up_meter;
    day += tree_height / (up_meter - down_meter);
    if((day - 1) * (up_meter - down_meter) < tree_height) ++day;
    printf("%d", day);
    return 0;
}