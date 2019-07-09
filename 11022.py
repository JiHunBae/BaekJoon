number_Of_Case = int(input())

for count in range(1, number_Of_Case + 1, 1):
    input_Value = input()
    numbers = list(map(int, input_Value.split(' ')))
    print("Case #",count,": ",numbers[0]," + ",numbers[1]," = ",(numbers[0] + numbers[1]), sep='')