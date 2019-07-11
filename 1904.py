length_Of_Sequence = int(input())

# P(n) = P(n-2) + P(n-1) 임을 이용하는 점화식
p_N_2 = 1 # 초기값은 크기가 1인 경우의 값 P(n-2)
p_N_1 = 2 # 초기값은 크기가 2인 경우의 값 P(n-1)
p_N = p_N_2 # 초기값은 크기가 1인 경우의 값 P(n)

for count in range(3, length_Of_Sequence + 1, 1):
    p_N = (p_N_2 + p_N_1) % 15746
    p_N_2 = p_N_1
    p_N_1 = p_N

print(p_N)