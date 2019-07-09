numbers = list(map(int, input().split(' ')))

while (not numbers[0] == 0) or (not numbers[1] == 0):
    print(numbers[0]+numbers[1])
    numbers = list(map(int, input().split(' ')))