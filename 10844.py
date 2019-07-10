number_Length = int(input())

def solve(length):
    dp = [[0 for col in range(10)] for row in range(length + 1)]
    # 초기 세팅(0번째 행은 헷갈리므로 무시하기로 함.)
    dp[1][0] = 0
    for index in range(1, 10, 1):
        dp[1][index] = 1

    for first_Index in range(2, length + 1, 1):
        dp[first_Index][0] = dp[first_Index - 1][1]
        for second_Index in range(1, 9, 1):
            dp[first_Index][second_Index] = ((dp[first_Index - 1][second_Index - 1] + dp[first_Index - 1][second_Index + 1]) % 1000000000)

        dp[first_Index][9] = dp[first_Index - 1][8]

    result = 0
    for count in range(0, 10, 1):
        result += dp[number_Length][count]
        result %= 1000000000

    return result

result_Of_Solve = solve(number_Length)
print(result_Of_Solve)
