#include <stdio.h>

#define BIGINT_MAXSIZE 40
void move_Hanoi(int number_Of_Circles, int move_From, int move_By, int move_To);
int* bigint_Multiplication(int *first_Factor,int first_Size, int *second_Factor, int second_Size, int *result);
void bigint_Print(int *number, int number_Array_Size);
void array_Copy(int *first_Array, int first_Array_Size, int *second_Array, int second_Array_Size);
void array_Reset(int *array, int array_Size);

int main() {
    int number_Of_Total_Circles;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    int result[BIGINT_MAXSIZE] = { 0 };
    int calc_Temp[40] = { - 1 };
    int a[BIGINT_MAXSIZE] = { 0 };
    int b[1] = { 0 };
    scanf("%d", &number_Of_Total_Circles);
    a[0] = 1;
    b[0] = 2;

    if(number_Of_Total_Circles > 20) {
        int count;
        for(count = 0; count < number_Of_Total_Circles; ++count) {
            array_Reset(result, BIGINT_MAXSIZE);
            bigint_Multiplication(a, BIGINT_MAXSIZE, b, 1, result);
            array_Copy(a, BIGINT_MAXSIZE, result, BIGINT_MAXSIZE);
        }
        result[0] -= 1;
        bigint_Print(result, BIGINT_MAXSIZE);
    } else {
        int mul_Temp = 2;
        int mul_Count, mul_Result;
        for(mul_Count = 0, mul_Result = 1; mul_Count < number_Of_Total_Circles; ++mul_Count) {
            mul_Result *= mul_Temp;
        }
        mul_Result -= 1;
        printf("%d\n", mul_Result);
        move_Hanoi(number_Of_Total_Circles, 1, 2, 3);
    }
}

void move_Hanoi(int number_Of_Moving_Circles, int move_From, int move_By, int move_To) {
    if(number_Of_Moving_Circles == 1) {
        printf("%d %d\n", move_From, move_To);
    } else {
        move_Hanoi(number_Of_Moving_Circles - 1, move_From, move_To, move_By);
        printf("%d %d\n", move_From, move_To);
        move_Hanoi(number_Of_Moving_Circles - 1, move_By, move_From, move_To);
    }
}

void bigint_Print(int *number, int number_Array_Size) {
    int index;
    for(index = number_Array_Size - 1; index >= 0; --index) {
        if(number[index] != 0)
            break;
    }

    for( ; index >= 0; --index) {
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
                temp_For_Plus = result[position_Of_First_Factor + position_Of_Second_Factor] + mul_Value_Current_Position;
                result[position_Of_First_Factor + position_Of_Second_Factor] = temp_For_Plus % 10;
                result[position_Of_First_Factor + position_Of_Second_Factor + 1] = (temp_For_Plus / 10) + mul_Value_Next_Position;
            } else {
                mul_Value_Current_Position = temp_Of_Mul_Each_Position;
                temp_For_Plus = result[position_Of_First_Factor + position_Of_Second_Factor] + mul_Value_Current_Position;
                result[position_Of_First_Factor + position_Of_Second_Factor] = temp_For_Plus % 10;
                result[position_Of_First_Factor + position_Of_Second_Factor + 1] = temp_For_Plus / 10;
            }
        }
    }
}

void array_Copy(int *first_Array, int first_Array_Size, int *second_Array, int second_Array_Size) {
    // fisrt_Array로 second_Array의 값을 가져온다. size가 동일한 경우만 복사하도록 구현함.
    if (first_Array_Size != second_Array_Size)
        return;

    int index;
    for(index = 0; index < first_Array_Size; ++index) {
        first_Array[index] = second_Array[index];
    }
}

void array_Reset(int *array, int array_Size) {
    int index;
    for(index = 0; index < array_Size; ++index) {
        array[index] = 0;
    }
}