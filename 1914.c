#include <stdio.h>

#define BIGINT_MAXSIZE 40
void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To);
void bigint_Print(int *number);
int main() {
    int number_Of_Total_Circles;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    char operator;
    int result[BIGINT_MAXSIZE] = { - 1 };
    int calc_Temp[40] = { - 1 };

    scanf("%d", &number_Of_Total_Circles);

    if(number_Of_Total_Circles > 20) {

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

int *bigint_Multiplication(int *first_Factor, int *second_Factor) {
    int first_Factor_Size = sizeof(first_Factor) / sizeof(int);
    int second_Factor_Size = sizeof(second_Factor) / sizeof(int);
    int multiplicatin_Result[BIGINT_MAXSIZE] =  { 0 };
    int temp_Of_Mul_Each_Position, position_Of_First_Factor, position_Of_Second_Factor;
    int mul_Value_Current_Position, mul_Value_Next_Position;

    for(position_Of_First_Factor = 0; position_Of_First_Factor < first_Factor_Size; ++position_Of_First_Factor) {
        for(position_Of_Second_Factor = 0; position_Of_Second_Factor < second_Factor_Size; ++position_Of_Second_Factor) {
            temp_Of_Mul_Each_Position = first_Factor[position_Of_First_Factor] * second_Factor[position_Of_Second_Factor];
            if(temp_Of_Mul_Each_Position > 9) {
                mul_Value_Current_Position = temp_Of_Mul_Each_Position % 10;
                mul_Value_Next_Position = temp_Of_Mul_Each_Position - mul_Value_Current_Position;
                mul_Value_Next_Position = mul_Value_Next_Position / 10;
                multiplicatin_Result[position_Of_First_Factor + position_Of_Second_Factor] =
            }
        }
    }
}