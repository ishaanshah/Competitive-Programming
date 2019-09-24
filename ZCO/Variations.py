#!usr/bin/python


def main():
    n, k = tuple(map(int, input().split()))
    value = list(map(int, input().split()))
    value.sort()
    count = 0
    memo = {}
    for num_1 in range(len(value)):
        if value[num_1] in memo:
            count += memo[value[num_1]]
        else:
            for num_2 in range(num_1 + 1, len(value)):
                if k <= abs(value[num_1] - value[num_2]):
                    num = n - num_2
                    count += num
                    memo[value[num_1]] = num
                    break

    print(count)

    
if __name__ == "__main__":
    main()
