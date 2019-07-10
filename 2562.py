number_Array = []
max_Value = 0
index_Of_Max_Value = 0
for count in range(0, 9, 1):
    number_Array.append(int(input()))

for index in range(0, 9, 1):
    if max_Value < number_Array[index]:
        max_Value = number_Array[index]
        index_Of_Max_Value = index

print('%d\n%d'%(max_Value, index_Of_Max_Value+1))