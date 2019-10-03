import sys
sys.setrecursionlimit(100001)
input = sys.stdin.readline


def do():
    array = get_array_from_input()
    array.sort()
    print(closest(array, 0, len(array)-1))


def closest(array, l, r):
    if (r-l+1) <= 3:
        return bruteforce(array, l, r)

    mid = int((r+l)/2)
    lfind = closest(array, l, mid)
    rfind = closest(array, mid+1, r)

    min_value = min(lfind, rfind)
    temp_list = []
    mid_x = array[mid][0]
    for search in array[l:r+1]:
        dist_x = search[0]-mid_x
        if dist_x ** 2 < min_value:
            temp_list.append(search)

    temp_list.sort(key=lambda element: element[1])

    for i in range(0, len(temp_list)-1):
        for j in range(i+1, len(temp_list)):
            k = temp_list[j][1] - temp_list[i][1]
            if k ** 2 < min_value:
                dist = (temp_list[j][0] - temp_list[i][0]) ** 2 + (temp_list[j][1] - temp_list[i][1]) ** 2
                min_value = min(min_value, dist)
            else:
                break

    return min_value


def bruteforce(array, l, r):
    min_value = (array[l+1][0] - array[l][0]) ** 2 + (array[l+1][1] - array[l][1]) ** 2

    for index_1 in range(l, r):
        for index_2 in range(index_1 + 1, r+1):
            min_value= min(min_value, (array[index_2][0]-array[index_1][0])**2+(array[index_2][1]-array[index_1][1])**2)

    return min_value


def get_array_from_input():
    number_of_points = int(input())
    array = []

    for count in range(number_of_points):
        x,y = map(int, input().split(' '))
        array.append((x,y))

    return array


do()