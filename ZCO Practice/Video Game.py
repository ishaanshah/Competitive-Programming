#!/usr/bin/python

state = []
crane_pos = 0
crane_status = False
h = 0
n = 0


def main():
    global state
    global n
    global h

    fline = input()
    n, h = map(int, fline.split())

    sline = input()
    state = list(map(int, sline.split()))

    tline = input()
    instructions = list(map(int, tline.split()))

    for instruction in instructions:
        if instruction == 1:
            move_left()
        elif instruction == 2:
            move_right()
        elif instruction == 3:
            pickup()
        elif instruction == 4:
            drop()

    print(*state, end='')


def move_left():
    global crane_pos
    if crane_pos > 0:
        crane_pos -= 1


def move_right():
    global crane_pos
    if crane_pos < n-1:
        crane_pos += 1


def pickup():
    global crane_status
    if not crane_status:
        crane_status = True
        state[crane_pos] -= 1


def drop():
    global crane_status
    if crane_status and state[crane_pos] < h:
        crane_status = False
        state[crane_pos] += 1


if __name__ == "__main__":
    main()
