#include <stdio.h>
int main() {
    int kg = 0;
    scanf("%d", &kg);

    if(kg <= 10) {
        if(kg == 4 || kg == 7)
            printf("%d", -1);
        else if(kg % 5 == 0)
            printf("%d", kg / 5);
        else // 3의 배수
            printf("%d", kg / 3);
    }
    else { // 11이상의 수
    /* 11kg이상의 수 에서는 3kg 설탕포대가 2 4 1 3 0 2 4 1 3 0....
     * 처럼 갯수가 반복되기에 이러한 점을 이용
     */
        int temp = kg - 10;
        switch(temp % 5) {
            case 0 :
                printf("%d", kg / 5);
                break;
            case 1 :
                printf("%d", (kg - 6) / 5 + 2);
                break;
            case 2 :
                printf("%d", (kg - 12) / 5 + 4);
                break;
            case 3 :
                printf("%d", (kg - 3) / 5 + 1);
                break;
            case 4 :
                printf("%d", (kg - 9) / 5 + 3);
                break;
             default : break;
        }
    }
    return 0;
}
