#include <stdio.h>

int input_Value();
void solve(int input_Number);
void print_Star(int point_Of_X, int point_Of_Y);

int main() {
    int input_Number = input_Value();
    solve(input_Number);
}



int input_Value() {
    int input_Num;
    scanf("%d", &input_Num);
    return input_Num;
}

void solve(int input_Number) {
    int x,y;
    for(x = 0; x < input_Number; ++x) {
        for(y = 0; y < input_Number; ++y) {
            print_Star(x, y);
        }
        printf("\n");
    }
}

void print_Star(int point_Of_X, int point_Of_Y) {
    if(point_Of_X % 3 == 1 && point_Of_Y % 3 == 1)
        printf(" ");
    else {
        if(point_Of_X / 3 == 0) // x,y 좌표값이 가운데 사각형에 들어오지 않는 경우
            printf("*");
        else // x,y 좌표값이 가운데 빈 사각형에 들어오는 경우
            print_Star(point_Of_X / 3, point_Of_Y / 3);
    }
}
