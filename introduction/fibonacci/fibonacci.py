# Uses python3
import sys

def calc_fib(n):
    if (n <= 1):
        return n
    return calc_fib(n - 1) + calc_fib(n - 2)

def fast_fib(n):
    fib = [0] * (n+1)
    fib[0] = 0
    fib[1] = 1
    for i in xrange(2,n+1):
        fib[i] = fib[i-1] + fib[i-2]
    return fib[n]

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fast_fib(n))
