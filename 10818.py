number_Of_Numbers = int(input())
number_Array = list(map(int, input().split(' ')))
max_Value = number_Array[0]
min_Value = number_Array[0]

for index in range(1, number_Of_Numbers, 1):
    if max_Value < number_Array[index]:
        max_Value = number_Array[index]
    if min_Value > number_Array[index]:
        min_Value = number_Array[index]

print(min_Value,max_Value)