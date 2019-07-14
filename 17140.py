target_Row, target_Col, target_Value = map(int, input().split(' '))
array_Row_Length, array_Col_Length = 3, 3
array = [[0] * 101 for _ in range(101)]

def solve():
    global array_Row_Length, array_Col_Length
    for calc_Time in range(101):
        if array[target_Row][target_Col] == target_Value:
            print(calc_Time)
            exit()
        if array_Row_Length >= array_Col_Length:
            for row_Index in range(1, array_Row_Length + 1):
                count = [0] * 101
                for col_Index in range(1, array_Col_Length + 1):
                    if array[row_Index][col_Index]:
                        count[array[row_Index][col_Index]] += 1
                        array[row_Index][col_Index] = 0
                number_Of_Times_Each_Value = []

                for col_Index in range(1, 101):
                    if count[col_Index]:
                        number_Of_Times_Each_Value.append((count[col_Index], col_Index))
                number_Of_Times_Each_Value.sort()
                array_Col_Length = max(array_Col_Length, number_Of_Times_Each_Value.__len__()*2)
                col_Index = 1
                for set_Of_Count in number_Of_Times_Each_Value:
                    array[row_Index][col_Index + 1], array[row_Index][col_Index] = set_Of_Count
                    col_Index += 2
        else:
            for col_Index in range(1, array_Col_Length + 1):
                count = [0] * 101
                for row_Index in range(1, array_Row_Length + 1):
                    if array[row_Index][col_Index]:
                        count[array[row_Index][col_Index]] += 1
                        array[row_Index][col_Index] = 0
                number_Of_Times_Each_Value = []
                for row_Index in range(1, 101):
                    if count[row_Index]:
                        number_Of_Times_Each_Value.append((count[row_Index], row_Index))
                number_Of_Times_Each_Value.sort()
                array_Row_Length = max(array_Row_Length, number_Of_Times_Each_Value.__len__()*2)
                row_Index = 1
                for set_Of_Count in number_Of_Times_Each_Value:
                    array[row_Index +1][col_Index], array[row_Index][col_Index] = set_Of_Count
                    row_Index += 2
    print(-1)

for r_Index in range(1, 4, 1):
    array[r_Index][1], array[r_Index][2], array[r_Index][3] = map(int, input().split())
solve()