#include <stdio.h>
#include <math.h>

// circles는 옮겨야 할 circle의 개수, from은 몇 번 라인에서 옮기는지, by는 몇 번 라인을 거치는지, to는 몇 번 라인에 도착하는지
//void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To);
void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To) {
    if(number_Of_Circles == 1) {
        printf("%d %d\n", move_From, move_To);
    } else {
        move_Hanoi(number_Of_Circles - 1, move_From, move_To, move_By);
        printf("%d %d\n", move_From, move_To);
        move_Hanoi(number_Of_Circles - 1, move_By, move_From, move_To);
    }
}
int main() {
    int number_Of_Total_Circles;
    scanf("%d", &number_Of_Total_Circles);
    printf("%d\n", (int)pow((double)2, number_Of_Total_Circles) - 1);
    move_Hanoi(number_Of_Total_Circles, 1, 2, 3);
    return 0;
}

