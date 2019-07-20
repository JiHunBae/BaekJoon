def solve():
    string = list(map(str, input()))
    string_Length = string.__len__()
    alphabet = [-1 for _ in range(26)]
    for index in range(string_Length):
        index_Of_Alphabet = ord(string[index]) - 97
        if alphabet[index_Of_Alphabet] is -1:
            alphabet[index_Of_Alphabet] = index

    print_Result(alphabet)

def print_Result(array):
    array_Length = array.__len__()
    for index in range(array_Length):
        print(array[index],end=' ')

solve()