def main():
    fileName = "../textfiles/day11final.txt"
    part_one(fileName)
    fileName = "../textfiles/day11final.txt"
    part_two(fileName)


def part_one(fileName):
    with open(file=fileName, encoding="utf8") as f:
        line = [int(x) for x in f.readline().split()]
        for _ in range(25):
            line = blink(line)

    print("Day 11 part one:", len(line))


def part_two(fileName):
    with open(file=fileName, encoding="utf8") as f:
        line = [int(x) for x in f.readline().split()]
        d = {}
        for x in line:
            if x not in d:
                d[x] = 1
            else:
                d[x] += 1
        # print(d)
        for _ in range(75):
            d = blink1(d)
        s = 0
        # print(d)
        for k, v in d.items():
            s += v
    # print(line)
    print("Day 11 part two:", s)


def blink(line):
    nline = []

    for x in line:
        if x == 0:
            nline.append(1)
        elif len(str(x)) % 2 == 0:
            l = len(str(x))
            s = str(x)[0:int(l/2)]
            s1 = str(x)[int(l/2):]
            nline.append(int(s))
            nline.append(int(s1))
        else:
            nline.append(x*2024)
    return nline


def blink1(d):
    d1 = dict()

    for k, v in d.items():
        # print(k, v)
        vals = blink([k])
        # print(vals)
        for v1 in vals:
            if v1 not in d1:
                d1[v1] = v
            else:
                d1[v1] += v
    # print(d1)
    return d1


main()
