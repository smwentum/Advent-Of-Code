import re
import heapq


def main():
    fileName = "../textfiles/day3final.txt"
    part_one(fileName)
    fileName = "../textfiles/day3final.txt"
    part_two(fileName)


def part_one(fileName):
    line = ""
    with open(fileName, encoding="utf8") as f:
        for x in f.read().splitlines():
            line += x
        # print(line)
        x = re.finditer(
            "mul\\([\\d]{1,3},[\\d]{1,3}\\)", line)

        sum_product = 0
        for m in x:
            # print(m.group())
            prod = m.group()[4:-1]
            # print(prod)
            a, b = prod.split(",")
            sum_product += int(a)*int(b)
        print("Day three part one:", sum_product)


def part_two(fileName):
    line = ""
    with open(fileName, encoding="utf8") as f:
        for x in f.read().splitlines():
            line += x
        # print(len(line))
        x = re.finditer(
            "mul\\([\\d]{1,3},[\\d]{1,3}\\)", line)

        find_do = re.finditer(
            "do\\(\\)", line)

        heapDo = []

        heapq.heapify(heapDo)
        heapq.heappush(heapDo, len(line))
        for x_do in find_do:
            # print(x_do.start(), x_do.end(), x_do.group())
            heapq.heappush(heapDo, x_do.start())

        find_dont = re.finditer(
            "don't\\(\\)", line)

        heapDont = []

        heapq.heapify(heapDont)

        for x_dont in find_dont:
            # print(x_dont.start(), x_dont.end(), x_dont.group())
            heapq.heappush(heapDont, x_dont.start())

        badIntervals = []
        # print(heapDont)

        # print("start", start)

        while len(heapDo) > 0 and len(heapDont) > 0:
            start = heapq.heappop(heapDont)

            while len(heapDo) > 0 and heapDo[0] < start:
                heapq.heappop(heapDo)

            if len(heapDo) > 0 and heapDo[0] > start:
                badIntervals.append((start, heapDo[0]))

        # print("Bad intervals: ",badIntervals)
        sum_product = 0
        for m in x:
            if any(max(badIntervals[i][0], m.start()) < min(badIntervals[i][1], m.end())
                    for i in range(len(badIntervals))):

                continue

            # print(m.group(),m.start(),m.end())
            prod = m.group()[4:-1]
            # print(prod)
            a, b = prod.split(",")
            sum_product += int(a)*int(b)
        print("Day three part two:", sum_product)


main()
