import re


def main():
    fileName = "../textfiles/day3final.txt"
    part_one(fileName)
    fileName = "../textfiles/day3test.txt"
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
        print("Day one part one:", sum_product)


def part_two(fileName):
    line = ""
    with open(fileName, encoding="utf8") as f:
        for x in f.read().splitlines():
            line += x
        # print(line)
        x = re.finditer(
            "mul\\([\\d]{1,3},[\\d]{1,3}\\)", line)

        find_do = re.finditer(
            "do\\(\\)", line)
        for x_do in find_do:
            print(x_do.start(), x_do.end(), x_do.group())

        find_dont = re.finditer(
            "don't\\(\\)", line)

        for x_dont in find_dont:
            print(x_dont.start(), x_dont.end(), x_dont.group())

        # sum_product = 0
        # for m in x:
        #     # print(m.group())
        #     prod = m.group()[4:-1]
        #     # print(prod)
        #     a, b = prod.split(",")
        #     sum_product += int(a)*int(b)
        # print("Day one part one:", sum_product)


main()
