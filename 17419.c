//#include <stdio.h>
//
//int main() {
//    int lengthOfBinary, index;
//    int calculationCount = 0;
//    char binaryString[1000000];
//
//    scanf("%d", &lengthOfBinary);
//    scanf("%s", binaryString);
//
//    for(index = 0; index < lengthOfBinary; ++index) {
//        if(binaryString[index] == 49) // 숫자 1이 아스키 값으로 49인 것을 이용
//            ++calculationCount;
//    }
//
//    printf("%d", calculationCount);
//    return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct __Gifticon {
//    int a;
//    int b;
//} Gifticon;
//
//int CompareA(const void *x, const void *y);
//int compareB(const void *x, const void *y);
//void printA(Gifticon *array, int arrayLength);
//void printB(Gifticon *array, int arrayLength);
//
//int main() {
//    int numberOfGiftiCon; // 기프티콘의 수
//    Gifticon gift[100000];
//    int index; // 배열 index값
//    int calcTemp; // 계산 시 임시로 사용되는 변수
//    int aOfPrevB, prevA;
//    long long extensionCount = 0; // 연장 횟수 카운트
//
//    scanf("%d", &numberOfGiftiCon); // 기프티콘 수 입력받음
//
//    for(index = 0; index < numberOfGiftiCon; ++index) { // 남은 기한 입력받음
//        scanf("%d", &gift[index].a);
//    }
//
//    for(index = 0; index < numberOfGiftiCon; ++index) {
//        scanf("%d", &gift[index].b);
//    }
//
//    qsort(gift, numberOfGiftiCon, sizeof(Gifticon), CompareA);
//    // b에 대한 정렬
//    qsort(gift, numberOfGiftiCon, sizeof(Gifticon), compareB);
//    printA(gift, numberOfGiftiCon);
//    printf("\n");
//    printB(gift, numberOfGiftiCon);
//    printf("\n");
//
//    // 첫 번째 대상에 대한 처리
//    //prevA = gift->a;
//    extensionCount += (gift[0].b - gift[0].a + 29) / 30;
//    gift[0].a += extensionCount * 30;
//    aOfPrevB = gift[0].a;
//
//    for(index = 1; index < numberOfGiftiCon; ++index) {
//        if(gift[index].b != gift[index - 1].b) {
//            aOfPrevB = gift[index - 1].a;
//        }
//
//        if((calcTemp = aOfPrevB - gift[index].a) > 0) { // aOfPRevB > gift[index].a
//            calcTemp = (calcTemp + 29) / 30;
//            gift[index].a += calcTemp * 30;
//            extensionCount += calcTemp;
//        }
//
//        if((calcTemp = gift[index].b - gift[index].a) > 0) {
//            calcTemp = (calcTemp + 29) / 30;
//            gift[index].a += calcTemp * 30;
//            extensionCount += calcTemp;
//        }
//    }
//    printA(gift, numberOfGiftiCon);
//    printf("\n");
//    printB(gift, numberOfGiftiCon);
//    printf("\n");
//    printf("%lld", extensionCount);
//    return 0;
//}
//
//int CompareA(const void *x, const void *y) {
//    Gifticon *giftX = (Gifticon *) x;
//    Gifticon *giftY = (Gifticon *) y;
//
//    if (giftX->a < giftY ->a) return -1;
//    else if(giftX->a > giftY->a) return 1;
//    else return 0;
//}
//
//int compareB(const void *x, const void *y) {
//    Gifticon *giftX = (Gifticon *) x;
//    Gifticon *giftY = (Gifticon *) y;
//
//    if (giftX->b < giftY ->b) {
//        return -1;
//    }
//    else if(giftX->b > giftY->b) return 1;
//    else {
//        if(giftX->a < giftY->a)
//            return -1;
//        else if(giftX->a > giftY->a)
//            return 1;
//
//        return 0;
//    }
//}
//
//void printA(Gifticon *array, int arrayLength) {
//    int index;
//
//    for(index = 0; index < arrayLength; ++index) {
//        printf("%d ", (array + index)->a);
//    }
//}
//
//void printB(Gifticon *array, int arrayLength) {
//    int index;
//
//    for(index = 0; index < arrayLength; ++index) {
//        printf("%d ", (array + index)->b);
//    }
//}


//////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct __Gifticon {
//    int a;
//    int b;
//} Gifticon;
//
//int Compare(const void *x, const void *y);
//
//int main() {
//    int numberOfGiftiCon; // 기프티콘의 수
//    Gifticon gift[100000];
//    int index; // 배열 index값
//    int calcTemp; // 계산 시 임시로 사용되는 변수
//    int aOfPrevB, prevA;
//    long long extensionCount = 0; // 연장 횟수 카운트
//
//    scanf("%d", &numberOfGiftiCon); // 기프티콘 수 입력받음
//
//    for(index = 0; index < numberOfGiftiCon; ++index) { // 남은 기한 입력받음
//        scanf("%d", &gift[index].a);
//    }
//
//    for(index = 0; index < numberOfGiftiCon; ++index) {
//        scanf("%d", &gift[index].b);
//    }
//
//    qsort(gift, numberOfGiftiCon, sizeof(Gifticon), Compare);
//
//    // 첫 번째 대상에 대한 처리
//    //prevA = gift->a;
//    extensionCount += (gift[0].b - gift[0].a + 29) / 30;
//    gift[0].a += extensionCount * 30;
//    aOfPrevB = gift[0].a;
//
//    for(index = 1; index < numberOfGiftiCon; ++index) {
//        if(gift[index].b != gift[index - 1].b) {
//            aOfPrevB = gift[index - 1].a;
//        }
//
//        if((calcTemp = aOfPrevB - gift[index].a) > 0) { // aOfPRevB > gift[index].a
//            calcTemp = (calcTemp + 29) / 30;
//            gift[index].a += calcTemp * 30;
//            extensionCount += calcTemp;
//        }
//
//        if((calcTemp = gift[index].b - gift[index].a) > 0) {
//            calcTemp = (calcTemp + 29) / 30;
//            gift[index].a += calcTemp * 30;
//            extensionCount += calcTemp;
//        }
//    }
//
//    printf("%d", extensionCount);
//
//    return 0;
//}
//
//int Compare(const void *x, const void *y) {
//    Gifticon *giftX = (Gifticon *) x;
//    Gifticon *giftY = (Gifticon *) y;
//
//    if (giftX->b < giftY ->b) {
//        return -1;
//    }
//    else if(giftX->b > giftY->b) return 1;
//    else {
//        if(giftX->a < giftY->a)
//            return -1;
//        else if(giftX->a > giftY->a)
//            return 1;
//
//        return 0;
//    }
//}