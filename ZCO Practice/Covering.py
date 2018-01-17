#!usr/bin/python


def main():
    n = int(input())
    interval = []
    for i in range(n):
        interval.append(tuple(map(int, input().split())))

    interval.sort(key=lambda item: item[1])
    elem = []
    for element in interval:
        if len(elem) != 0 and (element[0] <= elem[-1] <= element[1]):
            continue
        else:
            elem.append(element[1])
    print(len(elem))


if __name__ == '__main__':
    main()
