input_Value = input()
numbers = list(map(int, input_Value.split(' ')))
if numbers[0] > numbers[1]:
    print(">")
elif numbers[0] < numbers[1]:
    print("<")
else:
    print("==")
