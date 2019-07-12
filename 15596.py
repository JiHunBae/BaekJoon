def solve(a:list) -> int:
    ans = 0
    length = a.__len__()
    for index in range(length):
        ans += a[index]
    return ans