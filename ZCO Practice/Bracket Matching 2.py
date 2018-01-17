#!/usr/bin/python


def main():
    n = int(input())
    brackets = list(map(int, input().split()))
    depth = 0
    depths = []
    bracket_stack = []
    index_1 = []
    index_2 = []
    i = -1
    for idx, bracket in enumerate(brackets):
        i += 1
        if bracket == 1 or bracket == 3:
            bracket_stack.append((bracket, idx))
        elif bracket == 2 or bracket == 4:
            if bracket == 4:
                index_2.append((bracket, idx - bracket_stack.pop()[1] + 1))
            elif bracket == 2:
                index_1.append((bracket, idx - bracket_stack.pop()[1] + 1))

        if i > 0:
            if (brackets[idx - 1] == 1 or brackets[idx - 1] == 2) and bracket == 3:
                depth += 1
            elif (brackets[idx - 1] == 3 or brackets[idx - 1] == 4) and bracket == 1:
                depth += 1

        if not bracket_stack:
            depths.append(depth)
            depth = 0
            i = -1

    print(max(depths) + 1, max(index_1, key=lambda x: x[1])[1], max(index_2, key=lambda x: x[1])[1])


if __name__ == '__main__':
    main()
