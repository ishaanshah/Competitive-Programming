#!usr/bin/python


def main():
    n = int(input())
    seq = list(map(int, input().split()))
    print([dp(i) for i in range(n)])


def dp(idx):
    if idx == -1:
        return 0
    elif idx == 0:
        return 1
    else:
        return min([dp(j - 1) for j in range(0, idx)]) + 1



if __name__ == '__main__':
    main()
