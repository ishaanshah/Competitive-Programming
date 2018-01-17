#!/usr/bin/python


def main():
    n = int(input())
    brackets = list(map(int, input().split()))

    bracket_stack = []
    index_1 = 0
    index_2 = 0
    for idx, bracket in enumerate(brackets):
        if bracket == 1 or bracket == 3:
            bracket_stack.append((bracket, idx))
        else:
            if bracket == 4:
                index_2 = max(index_2, idx - bracket_stack.pop()[1] + 1)
            elif bracket == 2:
                index_1 = max(index_1, idx - bracket_stack.pop()[1] + 1)

    bracket_stack = []
    depth_stack = []
    ans = 1
    for bracket in brackets:
        if (bracket == 1 or bracket == 3) and not bracket_stack:
            bracket_stack.append(bracket)
            depth_stack.append(1)
            ans = max(ans, depth_stack[-1])

        elif bracket == 1 and bracket_stack[-1] == 3:
            bracket_stack.append(bracket)
            depth_stack.append(depth_stack[-1] + 1)
            ans = max(ans, depth_stack[-1])

        elif bracket == 3 and bracket_stack[-1] == 1:
            bracket_stack.append(bracket)
            depth_stack.append(depth_stack[-1] + 1)
            ans = max(ans, depth_stack[-1])

        elif bracket == 1 or bracket == 3:
            bracket_stack.append(bracket)
            depth_stack.append(depth_stack[-1])

        elif bracket == 2 or bracket == 4:
            bracket_stack.pop()
            depth_stack.pop()

    print(ans, index_1, index_2)


if __name__ == '__main__':
    main()
