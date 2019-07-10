number_Array = list(map(int, input().split(' ')))
previous_Number = number_Array[0]
for index in range(1, 8, 1):
    if number_Array[index] < previous_Number:
        break
    if index == 7:
        print("ascending")
        exit()
    previous_Number = number_Array[index]

previous_Number = number_Array[0]
for index in range(1, 8, 1):
    if number_Array[index] > previous_Number:
        break
    if index == 7:
        print("descending")
        exit()
    previous_Number = number_Array[index]

print("mixed")