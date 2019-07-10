from operator import eq

case_Num = int(input())

for count in range(0, case_Num, 1):
    quiz_Answer = list(map(str, input()))
    quiz_Length = quiz_Answer.__len__()
    score = [0 for col in range(quiz_Length)]
    sum = 0
    if eq('X', quiz_Answer[0]):
        score[0] = 0
    else:
        score[0] = 1
        sum = 1

    for index in range(1, quiz_Length, 1):
        if eq('X', quiz_Answer[index]):
            score[index] = 0
        else:
            score[index] = score[index - 1] + 1
            sum += score[index]

    print(sum)