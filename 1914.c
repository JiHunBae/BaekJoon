#include <stdio.h>

#define BIGINT_MAXSIZE 80
void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To);
int* bigint_Multiplication(int *first_Factor,int first_Size, int *second_Factor, int second_Size, int *result);
void bigint_Print(int *number);
int main() {
    int number_Of_Total_Circles;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    char operator;
    int result[BIGINT_MAXSIZE] = { - 1 };
    int calc_Temp[40] = { - 1 };
    int a[40] = { 0 };
    int b[40] = { 0 };
    printf("%d\n", sizeof(result) / sizeof(int));
    scanf("%d", &number_Of_Total_Circles);
    a[0] = 4;
    a[1] = 2;
    b[0] = 3;
    if(number_Of_Total_Circles > 20) {
        bigint_Multiplication(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]), result);
    } else {
        move_Hanoi(number_Of_Total_Circles, 1, 2, 3);
    }
}

void move_Hanoi(int number_Of_Moving_Circles, int move_From, int move_By, int move_To) {
    if(number_Of_Moving_Circles == 1) {
        printf("%d %d", move_From, move_To);
    } else {
        move_Hanoi(number_Of_Moving_Circles - 1, move_From, move_By, move_To);
        printf("%d %d", move_From, move_To);
        move_Hanoi(number_Of_Moving_Circles - 1, move_By, move_From, move_To);
    }
}

void bigint_Print(int *number) {
    int index;
    int number_Array_Size = sizeof(number) / sizeof(int);
    for(index = number_Array_Size - 1; index >= 0 && number[index] != -1; --index) {
        printf("%d", number[index]);
    }
}

int *bigint_Multiplication(int *first_Factor, int first_Size, int *second_Factor, int second_Size, int *result) {
    int multiplication_Result[BIGINT_MAXSIZE] = { 0 };
    int temp_Of_Mul_Each_Position, position_Of_First_Factor, position_Of_Second_Factor;
    int mul_Value_Current_Position, mul_Value_Next_Position;
    int temp_For_Plus;

    for(position_Of_First_Factor = 0; position_Of_First_Factor < first_Size; ++position_Of_First_Factor) {
        for(position_Of_Second_Factor = 0; position_Of_Second_Factor < second_Size; ++position_Of_Second_Factor) {
            temp_Of_Mul_Each_Position = first_Factor[position_Of_First_Factor] * second_Factor[position_Of_Second_Factor];
            if(temp_Of_Mul_Each_Position > 9) {
                mul_Value_Current_Position = temp_Of_Mul_Each_Position % 10;
                mul_Value_Next_Position = temp_Of_Mul_Each_Position - mul_Value_Current_Position;
                mul_Value_Next_Position = mul_Value_Next_Position / 10;
                temp_For_Plus = multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor] + mul_Value_Current_Position;
                multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor] = temp_For_Plus % 10;
                multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor + 1] = (temp_For_Plus / 10) + mul_Value_Next_Position;
            } else {
                mul_Value_Current_Position = temp_Of_Mul_Each_Position;
                temp_For_Plus = multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor] + mul_Value_Current_Position;
                multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor] = temp_For_Plus % 10;
                multiplication_Result[position_Of_First_Factor + position_Of_Second_Factor + 1] = temp_For_Plus / 10;
            }
        }
    }
}