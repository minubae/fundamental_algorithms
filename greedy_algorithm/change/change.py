# Uses python3
import sys

def get_change(m):
    # Create Array of denominations, that is, 1, 5, and 10.
    deno = [1, 5, 10]
    n = len(deno) / len(deno[0])

    # Initialize result
    size = 0
    # Traverse through all denomination
    for i in range(n-1, 0, -1): #for (i = n-1; i>=0; i--):
        # Find denominations
        while (m >= deno[i]):
            m = m - deno[i];
            size = size+1
    return size;

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
