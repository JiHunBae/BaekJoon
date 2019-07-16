def solve():
    sentence = list(map(str, input().split(' ')))
    max_Count = sentence.__len__()
    string_Count = 0
    for count in range(0, max_Count):
        if sentence[count] is not '':
            string_Count += 1
    print(string_Count)
solve()