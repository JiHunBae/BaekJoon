array_Row, array_Col = map(int, input().split(' '))
numbers = []
sum = [[0 for col in range(array_Col)] for row in range(array_Row)]

for row_Index in range(0, array_Row, 1):
    numbers.append(list(map(int, input().split(' '))))

sum[0][0] = numbers[0][0]
for index in range(1, array_Col, 1):
    sum[0][index] = sum[0][index - 1] + numbers[0][index]

for row_Index in range(1, array_Row, 1):
    sum[row_Index][0] = sum[row_Index - 1][array_Col - 1] + numbers[row_Index][0]
    for col_Index in range(1, array_Col, 1):
        sum[row_Index][col_Index] = sum[row_Index][col_Index - 1] + numbers[row_Index][col_Index]

number_Of_Case = int(input())

for count in range(0, number_Of_Case, 1):
    first_Row, first_Col, second_Row, second_Col = list(map(int, input().split(' ')))
    result = 0
    for sum_Count in range(first_Row - 1, second_Row, 1):
        result += sum[sum_Count][second_Col -1] - sum[sum_Count][first_Col - 1] + numbers[sum_Count][first_Col - 1]
    print(result)