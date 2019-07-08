def factorial(number):
    if number > 1:
        return number * factorial(number - 1)
    else:
        return 1

factorial_Number = int(input())
result = factorial(factorial_Number)
print(result)