#!/usr/bin/python
import sys


def main():
    n = input()
    string = input()

    if len(string) > int(2 * n):
        sys.exit()

    brackets = get_brackets(string)
    depth_brackets = get_depth(brackets)
    depth = max(depth_brackets)
    depth_pos = depth_brackets.index(depth) + 1

    longest_chain_brackets = get_longest_chain(brackets)
    longest_chain = max(longest_chain_brackets) + 1
    longest_chain_pos = longest_chain_brackets.index(longest_chain - 1) - longest_chain + 3

    print(str(depth) + " " + str(depth_pos) + " " + str(longest_chain) + " " + str(longest_chain_pos))


def get_brackets(string):
    brackets = []

    for character in string:
        if character.isnumeric() and character == "1":
            brackets.append(1)

        elif character.isnumeric() and character == "2":
            brackets.append(2)

    return brackets


def get_longest_chain(brackets):
    length = 0
    lengths = []
    open_count = 0
    close_count = 0
    for bracket in brackets:
        if bracket == 1:
            open_count += 1
            length += 1
        elif bracket == 2:
            close_count += 1
            length += 1

        if close_count == open_count:
            length = 0

        lengths.append(length)

    return lengths


def get_depth(brackets):
    depth = 0
    depth_brackets = []
    for bracket in brackets:
        if bracket == 1:
            depth += 1
        elif bracket == 2:
            depth -= 1
        depth_brackets.append(depth)

    return depth_brackets


if __name__ == "__main__":
    main()
