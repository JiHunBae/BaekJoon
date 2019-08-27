#include <stdio.h>
#include <stdlib.h>

typedef struct __Gifticon { // a와 b값 저장
    long long a;
    long long b;
} Gifticon;

int Compare(const void *x, const void *y); // 정렬을 위한 비교 함수
int Max(int numberOne, int numberTwo);

int main() {
    long long numberOfGiftiCon; // 기프티콘의 수
    Gifticon gift[100000];
    long long index; // index값
    long long calcTemp; // 계산 시 임시로 사용되는 변수
    long long aOfPrevB = 0; // b값이 현재의 값과 다른 직전 b값의 a값을 나타낸다.
    long long maxPrevAInSameB = 0;
    long long extensionCount = 0; // 기프티콘 연장 횟수 카운트

    scanf("%lld", &numberOfGiftiCon); // 기프티콘 수 입력받음

    for(index = 0; index < numberOfGiftiCon; ++index) { // 남은 기한 입력받음(Ai)
        scanf("%lld", &gift[index].a);
    }

    for(index = 0; index < numberOfGiftiCon; ++index) { // 사용 날짜 입력받음(Bi)
        scanf("%lld", &gift[index].b);
    }

    qsort(gift, numberOfGiftiCon, sizeof(Gifticon), Compare); // b에 대한 정렬 후, a에 대한 정렬(둘 다 오름차순)

    // 첫 번째 대상에 대한 처리
    if(gift[0].b > gift[0].a) {
        extensionCount += (gift[0].b - gift[0].a + 29) / 30;
        gift[0].a += extensionCount * 30;
    }

    maxPrevAInSameB = gift[0].a;
    aOfPrevB = maxPrevAInSameB;

    for(index = 1; index < numberOfGiftiCon; ++index) {
        if(gift[index].b != gift[index - 1].b) { // 직전의 b값과 다르다면 prevA값 갱신
            aOfPrevB = maxPrevAInSameB;
        }

        if((calcTemp = aOfPrevB - gift[index].a) > 0) { // aOfPRevB > gift[index].a
            calcTemp = (calcTemp + 29) / 30;
            gift[index].a += calcTemp * 30;
            extensionCount += calcTemp;
        }

        if((calcTemp = gift[index].b - gift[index].a) > 0) {
            calcTemp = (calcTemp + 29) / 30;
            gift[index].a += calcTemp * 30;
            extensionCount += calcTemp;
        }

        maxPrevAInSameB = Max(maxPrevAInSameB, gift[index].a);
    }

    printf("%lld", extensionCount);

    return 0;
}

int Compare(const void *x, const void *y) {
    Gifticon *giftX = (Gifticon *) x;
    Gifticon *giftY = (Gifticon *) y;

    if (giftX->b < giftY ->b) {
        return -1;
    }
    else if(giftX->b > giftY->b) return 1;
    else {
        if(giftX->a < giftY->a)
            return -1;
        else if(giftX->a > giftY->a)
            return 1;

        return 0;
    }
}

int Max(int numberOne, int numberTwo) {
    return (numberOne > numberTwo) ? numberOne : numberTwo;
}