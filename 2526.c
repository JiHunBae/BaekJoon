#include <stdio.h>

#define MAX_SIZE_OF_ARRAY 98

typedef enum {false, true};
int main() {
    int first_Number, division_Value, current_Value, index;
    int iter_Check[MAX_SIZE_OF_ARRAY] = {0};
    int count = 0;
    scanf("%d", &first_Number);
    scanf("%d", &division_Value);

    if (first_Number > 1 && first_Number < 98)
        iter_Check[first_Number] = 1;

    current_Value = first_Number;

    while (true) {
        current_Value = (current_Value * first_Number) % division_Value;
        if (iter_Check[current_Value] == 2)
            break;

        ++iter_Check[current_Value];
    }

    for(index = 0; index < 98; ++index)
        if (iter_Check[index] == 2)
            ++count;

    printf("%d", count);


    return 0;
}