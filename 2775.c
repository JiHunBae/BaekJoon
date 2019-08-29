#include <stdio.h>

int main() {
    int numberOfTestcase; // 테스트 케이스 개수
    int k, n; // k는 층, n은 호실 번호
    int sum;
    int countingCase;
    int peopleInEachHouse[15][15] = { 0 };

    int indexK, indexN, sumCalcIndex; // k층과 n호를 표현하기 위한 인덱스 변수

    for(indexK = 0, indexN = 1; indexN <= 14; ++indexN) {
        peopleInEachHouse[0][indexN] = indexN;
    }

    for(indexK = 1; indexK <= 14; ++indexK) {
        for(indexN = 1; indexN <= 14; ++indexN) {
            for(sumCalcIndex = 1, sum = 0; sumCalcIndex <= indexN; ++sumCalcIndex) {
                sum += peopleInEachHouse[indexK - 1][sumCalcIndex];
            }

            peopleInEachHouse[indexK][indexN] = sum;
        }


    }


    scanf("%d", &numberOfTestcase);

    for(countingCase = 0; countingCase < numberOfTestcase; ++countingCase) {
        scanf("%d %d", &k, &n);
        printf("%d\n", peopleInEachHouse[k][n]);
    }

    return 0;
}