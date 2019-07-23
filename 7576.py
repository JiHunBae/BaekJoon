from collections import deque

def solve():
    input_Value = list(map(int, input().split(' ')))
    number_Of_Columns = input_Value[0]
    number_Of_Rows = input_Value[1]
    queue = deque()

    tomato = [] # 토마토가 익을 최소 날짜 저장 ( 1부터 시작하므로 -1을 반드시 해주고 출력)
    for index in range(number_Of_Rows):
        tomato.append(list(map(int, input().split(' '))))

    for row in range(number_Of_Rows):
        for col in range(number_Of_Columns):
            if tomato[row][col] is 1:
                queue.append((row, col))

    while queue.__len__() is not 0:
        row_Index, col_Index = queue.popleft()

        if row_Index > 0:
            if tomato[row_Index - 1][col_Index] is 0:
                queue.append((row_Index - 1, col_Index))
                tomato[row_Index - 1][col_Index] = tomato[row_Index][col_Index] + 1
        if row_Index < (number_Of_Rows - 1):
            if tomato[row_Index + 1][col_Index] is 0:
                queue.append((row_Index + 1, col_Index))
                tomato[row_Index + 1][col_Index] = tomato[row_Index][col_Index] + 1
        if col_Index > 0:
            if tomato[row_Index][col_Index - 1] is 0:
                queue.append((row_Index, col_Index - 1))
                tomato[row_Index][col_Index - 1] = tomato[row_Index][col_Index] + 1
        if col_Index < (number_Of_Columns - 1):
            if tomato[row_Index][col_Index + 1] is 0:
                queue.append((row_Index, col_Index + 1))
                tomato[row_Index][col_Index + 1] = tomato[row_Index][col_Index] + 1

    max_Value = 1
    for row in range(number_Of_Rows):
        for col in range(number_Of_Columns):
            if tomato[row][col] is 0:
                print(-1)
                exit(0)
            max_Value = max(max_Value, tomato[row][col])

    print(max_Value - 1)

solve()