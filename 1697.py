from collections import deque

def solve():
    queue = deque()
    input_Value = list(map(int, input().split(' ')))
    position_Of_Subin = input_Value[0]
    position_Of_Sister = input_Value[1]
    queue.append(position_Of_Subin)
    time = [111111 for _ in range(100001)]
    visit = [0 for _ in range(100001)]
    time[position_Of_Subin] = 0
    while queue.__len__() is not 0:

        index = queue.popleft()
        if index is position_Of_Sister:
            break
        elif visit[index] is 1:
            continue
        visit[index] = 1
        if index == 0: # 배열의 맨 왼쪽인 경우 +1밖에 안되므로 해당 경우 처리
            if visit[1] is 0:
                queue.append(1)
            time[1] = min(time[1], time[0] + 1)
        elif index == 100000: # 배열의 맨 오른쪽인 경우 -1밖에 안되므로 해당 경우 처리
            if visit[99999] is 0:
                queue.append(99999)
            time[99999] = min(time[99999], time[100000] + 1)
        else:
            # 배열의 가장자리가 아닌 경우
            if time[index] + 1 < time[index - 1]:
                time[index - 1] = time[index] + 1
                queue.append(index - 1)
            if time[index] + 1 < time[index + 1]:
                time[index + 1] = time[index] + 1
                queue.append(index + 1)
            if index < 50001 and time[index] + 1 < time[index << 1]:
                time[index << 1] = time[index] + 1
                queue.append(index << 1)

    print(time[position_Of_Sister])

solve()
