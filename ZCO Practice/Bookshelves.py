#!usr/bin/python


def main():
    inp = list(map(int, input().split()))
    n = inp[0]
    k = inp[1]
    shelf_1 = inp[2:n + 2]
    shelf_2 = inp[n + 2:]
    shelf_1.sort()
    shelf_2.sort()
    shelf_3 = shelf_1[:]
    shelf_4 = shelf_2[:]
    for i in range(k):
        shelf_1[-1], shelf_2[0] = shelf_2[0], shelf_1[-1]
        shelf_1.sort()
        shelf_2.sort()

        shelf_4[-1], shelf_3[0] = shelf_3[0], shelf_4[-1]
        shelf_3.sort()
        shelf_4.sort()

    print(min(shelf_1[-1] + shelf_2[-1], shelf_3[-1] + shelf_4[-1]))


if __name__ == "__main__":
    main()
