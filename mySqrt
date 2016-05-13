def MySqrt(c):
    i = 0
    x = c       # y = x * x - c
    while True:
        print(i, end = ' ')
        i = i + 1
        y = x * x - c
        if abs(y) < 0.0000000000001:
            print('\n', '%0.6f' % x, '\n')
            break
        x = x - y / (2 * x)

c = eval(input('input a number\n'))
MySqrt(c)
