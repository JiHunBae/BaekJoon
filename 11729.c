#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int move_Count = 0;
char *move_Information_String = "";
char *temp_String = "";
// circles는 옮겨야 할 circle의 개수, from은 몇 번 라인에서 옮기는지, by는 몇 번 라인을 거치는지, to는 몇 번 라인에 도착하는지
void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To);

int main() {
    int number_Of_Total_Circles;
    scanf("%d", &number_Of_Total_Circles);
    move_Hanoi(number_Of_Total_Circles, 1, 2, 3);
    printf("%d\n", move_Count);
    printf(move_Information_String);
}

void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To) {
    if(number_Of_Circles == 1) {
        temp_String = move_From + " " + move_To;
        strcat(move_Information_String, temp_String);
        strcat(move_Information_String, "\n");
    } else {
        ++move_Count;
        move_Hanoi(number_Of_Circles - 1, move_From, move_To, move_By);
        temp_String = move_From + " " + move_To;
        strcat(move_Information_String, temp_String);
        strcat(move_Information_String, "\n");
        move_Hanoi(number_Of_Circles - 1, move_By, move_From, move_To);
    }
}