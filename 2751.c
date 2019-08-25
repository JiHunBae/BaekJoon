#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y) {int temp = x; x = y; y = temp;}

void quick_sort(int *array, int left, int right) {
    int low = left, high = right;
    int pivot = array[(left + right) / 2];

    while(low <= high) {
        while(pivot > array[low])
            ++low;

        while(pivot < array[high])
            --high;

        if(low <= high) {
            SWAP(array[low], array[high]);
            ++low, --high;
        }

        if(left < high)
            quick_sort(array, left, high);

        if(low < right)
            quick_sort(array, low, right);
    }
}
int main() {
    int length_of_numbers, index;
    scanf("%d", &length_of_numbers);
    int *numbers = (int *) malloc(sizeof(int) * length_of_numbers);


    for(index = 0; index < length_of_numbers; ++index) {
        scanf("%d", &numbers[index]);
    }

    quick_sort(numbers, 0, length_of_numbers - 1);

    for(index = 0; index < length_of_numbers; ++index) {
        printf("%d\n", numbers[index]);
    }

    return 0;
}
