def solve():
    fibonacci_Count = int(input())
    fn1 = 1
    fn2 = 1
    fn = 0
    if fibonacci_Count is 1 or 2:
        fn = 1

    for count in range(3, fibonacci_Count + 1):
        fn = fn1 + fn2
        fn2 = fn1
        fn1 = fn

    print(fn)
solve()7