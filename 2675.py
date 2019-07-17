def solve():
    number_Of_Case = int(input())
    for count in range(number_Of_Case):
        array = list(map(str, input().split(' ')))
        number_Of_Repetitions = int(array[0])
        string = list(map(str, array[1]))
        for index in range(string.__len__()):
            for repeat_Count in range(number_Of_Repetitions):
                print(string[index], end='')
        print(end='\n')
solve()