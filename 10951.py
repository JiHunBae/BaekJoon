while True:
    try:
        input_Value = input()
        numbers = list(map(int, input_Value.split(' ')))
        print(numbers[0] + numbers[1])
    except EOFError:
        exit()