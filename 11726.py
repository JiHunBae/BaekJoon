size_Of_Tile = int(input()) # 숫자 입력받음
previous_Count = 0 # 이전 값
current_Count = 0 # 현재 값
if size_Of_Tile == 1: # 길이가 1인 경우 경우의 수는 길이의 값과 같다.
    current_Count = size_Of_Tile
elif size_Of_Tile == 2: # 길이가 2인 경우 경우의 수는 길이의 값과 같다.
    current_Count = size_Of_Tile
else: # 길이가 3이상인 경우 결과값 계산
    # 초기세팅
    previous_Count = 1
    current_Count = 2

    #점화식을 이용한 결과값 계산
    for a in range(3, size_Of_Tile+1, 1):
        store_Count = current_Count
        current_Count += previous_Count
        previous_Count = store_Count

result = current_Count % 10007 # 문제에서 10007로 나눈 나머지값을 구하라 했으므로 나머지 연산 진행
print(result)