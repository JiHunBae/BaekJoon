'''
주어진 수가 1, 2인 경우에는 1을 출력하게 한다. 이 부분은 피보나치의 첫 부분과 같다.
주어진 수가 1, 2가 아닌 경우에는 피보나치 수열을 계산하는 방식으로 결과값을 도출 후 출력하게 하는 함수이다.
'''
def solution(number):
    result = 0
    if number == 1 or number == 2:
        result = 1
    else:
        previous1 = 1
        previous2 = 1
        for count in range(3, number+1, 1):
            result = previous1 + previous2
            previous2 = previous1
            previous1 = result

    print(result)

receive_Number = int(input()) # 숫자 입력받음
solution(receive_Number) # 입력받은 숫자에 대한 함수 실행