first_Num = int(input())
second_Num = int(input())

first_Of_Second_Num = second_Num % 10
second_Of_Second_Num = int((second_Num % 100) / 10)
third_Of_Second_Num = int(second_Num / 100)

first_Mul = first_Num * first_Of_Second_Num
second_Mul = first_Num * second_Of_Second_Num
third_Mul = first_Num * third_Of_Second_Num

mul = first_Mul + (second_Mul * 10) + (third_Mul * 100)

print(first_Mul)
print(second_Mul)
print(third_Mul)
print(mul)