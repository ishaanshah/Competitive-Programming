#!/usr/bin/python


def main():
    n = input()
    budgets = []
    for i in range(int(n)):
        budgets.append(int(input()))

    budgets.sort()

    memo = {}

    for idx, price in enumerate(budgets):
        if price not in memo:
            memo[price] = price * (len(budgets) - idx)

    print(max(memo.values()))


if __name__ == "__main__":
    main()
