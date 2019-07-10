numbers = []
mod = [0 for col in range(42)]
different_Num = 0

for count in range(0, 10, 1):
    numbers.append(int(input()))

for index in range(0, 10, 1):
    mod[numbers[index] % 42] = 1

for index in range(0, 42, 1):
    if mod[index] == 1:
        different_Num += 1

print(different_Num)