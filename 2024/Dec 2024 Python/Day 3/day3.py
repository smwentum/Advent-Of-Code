import re


def main():
    fileName = "../textfiles/day3final.txt"
    part_one(fileName)


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


main()
