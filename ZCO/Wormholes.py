#!usr/bin/python

import bisect


def main():
    n, x, y = tuple(map(int, input().split()))
    contest = []
    for i in range(n):
        contest.append(tuple(map(int, input().split())))
    v = list(map(int, input().split()))
    w = list(map(int, input().split()))
    v = sorted(v)
    w = sorted(w)
    print(min(time_taken(contest, v, w)))


def time_taken(contests, v, w):
    diff = []
    for contest in contests:
        s = bisect.bisect_right(v, contest[0]) - 1
        e = bisect.bisect_left(w, contest[1])
        if s == -1 or e == len(w):
            diff.append(float("inf"))
        else:
            diff.append(w[e] - v[s] + 1)

    return diff


if __name__ == "__main__":
    main()
