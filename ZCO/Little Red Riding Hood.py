#!usr/bin/python

import sys

sys.setrecursionlimit(1000000000)
berry = []
is_safe = []
charms = []
memo = {}
n = 0


def main():
    global is_safe
    global n
    n, m = tuple(map(int, input().split()))
    for i in range(n):
        berry.append(list(map(int, input().split())))

    for i in range(m):
        charms.append(list(map(int, input().split())))

    for i in range(n):
        is_safe.append([])
        for j in range(n):
            is_safe[i].append(False)

    for charm in charms:
        x, y, k = charm[0] - 1, charm[1] - 1, charm[2]
        for i in range(max(0, x - k), min(n, x + k + 1)):
            for j in range(max(0, y - k), min(n, y + k + 1)):
                if abs(x - i) + abs(y - j) <= k:
                    is_safe[i][j] = True

    val = dp(0, 0)
    if val == float('-inf'):
        print('NO')
    else:
        print('YES')
        print(val)


def dp(x, y):
    if (x, y) in memo:
        return memo[x, y]
    elif x >= n or y >= n:
        return float('-inf')
    elif is_safe[x][y]:
        if x == n - 1 and y == n - 1:
            val = berry[x][y]
        else:
            val = max(dp(x + 1, y), dp(x, y + 1)) + berry[x][y]
        memo[x, y] = val
        return val
    else:
        val = float('-inf')
        memo[x, y] = val
        return val


if __name__ == '__main__':
    main()
