#!/usr/bin/python

import sys

mins = []
n = 0
memo = {}

sys.setrecursionlimit(1000000000)


def main():
    global n
    global mins
    n = int(input())
    mins = input().strip().split()
    for j in range(n):
        try:
            mins[j] = int(mins[j])
        except:
            pass

    n = len(mins)
    print(sum(mins) - min([dp(idx) for idx in range(3)]))


def dp(idx):
    global memo
    if idx in memo:
        return memo[idx]
    if n - 3 <= idx <= n:
        num = mins[idx]
    else:
        num = min(dp(idx + 1) + mins[idx], dp(idx + 2) + mins[idx], dp(idx + 3) + mins[idx])
        memo[idx] = num
    return num


if __name__ == "__main__":
    main()
