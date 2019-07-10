first_Num = int(input())
second_Num = int(input())
third_Num = int(input())
mul_Result = first_Num * second_Num * third_Num
# Int를 String으로 변환하고 map(int, )함수를 쓰면 문자 하나씩 int로 형변환 하여 list타입으로 만든 후 변수에 저장
numbers= list(map(int, str(mul_Result)))
numbers_Length = numbers.__len__()
numbers_Count = [0 for col in range(10)]

for index in range(0, numbers_Length, 1):
    numbers_Count[numbers[index]] += 1

for index in range(0, 10, 1):
    print(numbers_Count[index])