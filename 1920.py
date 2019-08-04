def solve():
    number_Of_Integers = int(input())
    number_Arrays = list(map(int, input().split(' ')))
    number_Of_Find_Integers = int(input())
    find_Integers = list(map(int, input().split(' ')))
    for count in range(number_Of_Integers):
        temp = False
        for find_Count in range(number_Of_Find_Integers):
            if number_Arrays[count] == find_Integers[find_Count]:
                print(1)
                temp = True
                break
        if temp is False:
            print(0)

solve()