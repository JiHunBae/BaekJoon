def solve():
    array_Of_Input_Value = list(map(str, input().split(' ')))
    first_Num = ''.join(reversed(array_Of_Input_Value[0]))
    second_Num = ''.join(reversed(array_Of_Input_Value[1]))
    max_Num = max(first_Num, second_Num)
    print(max_Num)
solve()