#!usr/bin/python

from bisect import bisect_left


def main():
    inp = list(map(int, input().split()))
    n = inp[0]
    bamboos = inp[1:]
    bamboos.sort()
    length = []
    for i in range(n):
        for j in range(i + 1, n):
            diff = bamboos[j] - bamboos[i]
            temp = bamboos[j] + diff
            count = 2
            while binary_search(bamboos, temp):
                temp += diff
                count += 1
            length.append(count)
    print(max(length))


def binary_search(a, x):
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return True
    return False


if __name__ == '__main__':
    main()
