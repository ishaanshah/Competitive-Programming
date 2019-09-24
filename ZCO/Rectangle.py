#!usr/bin/python


def main():
    n = int(input())
    stack = []
    y = [500 for _ in range(100005)]
    lefts = [0 for _ in range(100005)]
    rights = [100000 for _ in range(100005)]
    y[0] = y[100000] = 0

    for _ in range(n):
        a, b = tuple(map(int, input().split()))
        y[a] = min(y[a], b)

    for i in range(100001):
        while stack and y[stack[-1]] >= y[i]:
            stack.pop()

        if not stack:
            lefts[i] = 0
        else:
            lefts[i] = stack[-1]

        if y[i] != 500:
            stack.append(i)

    stack = []

    for i in range(100001, 0, -1):
        while stack and y[stack[-1]] >= y[i]:
            stack.pop()

        if not stack:
            rights[i] = 100000
        else:
            rights[i] = stack[-1]

        if y[i] != 500:
            stack.append(i)

    area = 100000
    for i in range(100001):
        temp = y[i] * (rights[i] - lefts[i])
        area = max(area, temp)

    print(area)


if __name__ == '__main__':
    main()
