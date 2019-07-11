case_Num = int(input())
dp = [0 for col in range(101)]
dp[1] = 1
dp[2] = 1
dp[3] = 1

for index in range(3, 101, 1):
    dp[index] = dp[index - 2] + dp[index -3]

for count in range(0, case_Num, 1):
    n = int(input())
    print(dp[n])