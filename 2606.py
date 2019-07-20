from collections import deque

def solve():
    queue = deque()
    number_Of_Computer = int(input())
    number_Of_Connect = int(input())
    connect = [[0] * (number_Of_Computer + 1) for _ in range(number_Of_Computer + 1)] # Connect state each computer (Connected == 1, not == 0)
    virus = [0 for _ in range(number_Of_Computer + 1)] # Whether computer be infected by virus(infected == 1, not == 0)

    # Connect each computer
    for count in range(number_Of_Connect):
        value = list(map(int, input().split(' ')))
        first_Num = value[0]
        second_Num = value[1]
        connect[first_Num][second_Num] = 1
        connect[second_Num][first_Num] = 1

    virus[1] = 1
    queue.append(1)
    number_Of_Infected_Computer = 0

    while queue.__len__() is not 0:
        index_Of_Infected_Computer = queue.popleft()
        for index_Of_Computer in range(number_Of_Computer + 1):
            if connect[index_Of_Infected_Computer][index_Of_Computer] is 1 and virus[index_Of_Computer] is 0:
                virus[index_Of_Computer] = 1
                number_Of_Infected_Computer += 1
                queue.append(index_Of_Computer)

    print(number_Of_Infected_Computer)
solve()