#!usr/bin/python

import bisect


def main():
    n, k = tuple(map(int, input().split()))
    hardness = list(map(int, input().split()))
    hardness.sort()
    count = 0

    for idx, elem in enumerate(hardness):
        i = find_lt(hardness, k - elem)
        num = i - idx
        if i != -1 and num > 0:
            count += num

    print(count)


def find_lt(a, x):
    i = bisect.bisect_left(a, x)
    return i - 1


if __name__ == "__main__":
    main()
