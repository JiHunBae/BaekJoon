def solve():
    index = 0
    max_Value = sequence[index]

    while index < number_Of_Sequence:
        add_Value = sequence[index]
        current_Max_Value = add_Value
        index += 1
        while index < number_Of_Sequence and add_Value > 0:
            add_Value += sequence[index]
            current_Max_Value = max(current_Max_Value, add_Value)
            index += 1

        max_Value = max(max_Value, current_Max_Value)

    return max_Value

number_Of_Sequence = int(input())
input_Sequence = input().split(' ')
sequence = list(map(int, input_Sequence))
continuous_Sum = []

result = solve()
print(result)