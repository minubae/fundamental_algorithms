# Uses python3
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10

def get_fibonacci_last_digit(n):
    fib = [0]*(n+1)
    fib[0] = 0
    fib[1] = 1
    for i in xrange(2,n+1):
        fib[i] = (fib[i-1] + fib[i-2]) % 10
    return fib[n]

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(get_fibonacci_last_digit_naive(n))
