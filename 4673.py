check_Array = [0 for col in range(10001)]
def main():
    for count in range(1, 10001, 1):
        producer(count)

    for check_Index in range(1, 10001, 1):
        if check_Array[check_Index] is 0:
            print(check_Index)

def producer(number):
    each_Number = list(map(int, str(number)))
    total = number
    for index in range(each_Number.__len__()):
        total += each_Number[index]

    if total < 10001:
        check_Array[total] = 1


main()