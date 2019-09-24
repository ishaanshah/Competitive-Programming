#!/usr/bin/python


def main():
    n = input()
    strength = input().split()
    strength = [int(elem) for elem in strength]
    strength.sort()
    score = 0
    for idx, elem in enumerate(strength):
        score += int(elem) * (2*idx - int(n) + 1)

    print(score)


if __name__ == "__main__":
    main()
