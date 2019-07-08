input_Value = input().split(' ')
time = list(map(int, input_Value))

hour = 0
minute = 1

if time[minute] > 45:
    time[minute] -= 45
else:
    time[minute] += 15
    if time[hour] == 0:
        time[hour] = 23
    else:
        time[hour] -= 1

print(time[hour],time[minute])