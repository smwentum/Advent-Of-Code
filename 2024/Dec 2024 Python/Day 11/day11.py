def main():
    fileName = "../textfiles/day11final.txt"
    part_one(fileName)


def part_one(fileName):
    with open(file=fileName, encoding="utf8") as f:
        line = [int(x) for x in f.readline().split()]
        for _ in range(25):
            line = blink(line)

    print("Day 11 part one:", len(line))


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


main()
