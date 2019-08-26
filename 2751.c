#include <stdio.h>

#define SWAP(x, y) {int temp; temp = x; x = y; y = temp;}

void QuickSort(int data[], int start, int end);
void Swap(int* firstNumber, int* secondNumber);

int main() {
    int lengthOfNumbers;
    int numbers[1000000];
    int index;

    scanf("%d", &lengthOfNumbers);

    for(index = 0; index < lengthOfNumbers; ++index) {
        scanf("%d", &numbers[index]);
    }

    QuickSort(numbers, 0, lengthOfNumbers - 1);

    for(index = 0; index < lengthOfNumbers; ++index) {
        printf("%d\n", numbers[index]);
    }

    return 0;
}

void QuickSort(int data[], int start, int end) {
    int left = start, right = end;
    int pivot = data[(start + end) / 2];

    while(left <= right) {
        while(pivot > data[left]) ++left;
        while(pivot < data[right]) --right;

        if(left <= right) {
            Swap(&data[left], &data[right]);
            ++left, --right;
        }
    }

    if(start < right) QuickSort(data, start, right);
    if(left < end) QuickSort(data, left, end);
}

void Swap(int* firstNumber, int* secondNumber) {
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}
