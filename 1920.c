#include <stdio.h>
#include <stdlib.h>

int static Compare(const void* first, const void* second);
int BinarySearch(const int* searchArray, int numberOfElements , int searchValue);

int main() {
    int numbers[100000] = { 0 }; // A[N]
    int indexOfNumbers, searchCount;
    int numberOfNumbers, numberOfSearchNumbers;
    int searchNumber;
    /*
     * indexOfNumbers는 A[N] 입력을 위한 index, searchCount는 몇 번째 검색인지를 나타내는 변수
     * numberOfNumbers는 A[N]에서 N의 개수에 해당, numberOfSearchNumber는 검색할 대상 개수
     * inputSearchNumber는 존재하는지 검사해야할 숫자를 의미
     */

    scanf("%d", &numberOfNumbers);

    // A[N] 저장
    for(indexOfNumbers = 0; indexOfNumbers < numberOfNumbers; ++indexOfNumbers) {
        scanf("%d", &numbers[indexOfNumbers]);
    }

    // A를 오름차순으로 정렬
    qsort(numbers, numberOfNumbers, sizeof(int), Compare);


    scanf("%d", &numberOfSearchNumbers);

    // Search
    for(searchCount = 0; searchCount < numberOfSearchNumbers; ++searchCount) {
        scanf("%d", &searchNumber);
        printf("%d\n", BinarySearch(numbers, numberOfNumbers, searchNumber));
    }

    return 1;
}

int static Compare (const void* first, const void* second) {
    int firstValue = *(int *)first;
    int secondValue = *(int *)second;

    if(firstValue > secondValue)
        return 1;
    else if(firstValue < secondValue)
        return -1;
    else
        return 0;
}

int BinarySearch(const int* searchArray, int numberOfElements , int searchValue) {
    int startIndex = 0;
    int endIndex = numberOfElements - 1;
    int midIndex;

    while(endIndex - startIndex > 0) {
        midIndex = (startIndex + endIndex) / 2;
        if(searchValue == searchArray[midIndex])
            return 1;

        if(searchValue < searchArray[midIndex]) {
            endIndex = midIndex - 1;
        } else if(searchValue > searchArray[midIndex]) {
            startIndex = midIndex + 1;
        }
    }
    midIndex = (startIndex + endIndex) / 2;
    if(searchValue == searchArray[midIndex])
        return 1;
    else
        return 0;
}
