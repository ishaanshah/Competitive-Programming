#!usr/bin/python

import sys

sys.setrecursionlimit(1000000000)

n = 0
price = []
memo = {}


def main():
    global n
    global price
    n = int(input())
    price = list(map(int, input().split()))
    print(min(dp(0, 0), dp(1, 1)))


def dp(idx, passed_val):
    if (idx, passed_val) in memo:
        return memo[idx, passed_val]

    if (idx == n - 2 and passed_val == 0) or idx == n - 1:
        num = price[idx]
    elif idx == n - 2 and passed_val == 1:
        num = price[idx] + price[idx + 1]
    else:
        num = min(dp(idx + 1, passed_val), dp(idx + 2, passed_val)) + price[idx]
        memo[idx, passed_val] = num
    return num


if __name__ == "__main__":
    main()
