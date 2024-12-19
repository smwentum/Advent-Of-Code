def main():

    file_name = "../textfiles/day19final.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        towelPatterns = [x.strip() for x in lines[0].split(",")]
        # print(lines)
        # print(towelPatterns)
        desgin = dict()
        desgin[""] = True
        for towelPattern in towelPatterns:
            desgin[towelPattern] = True

        cnt = 0
        for i, line in enumerate(lines):
            if i > 1:
                if is_possible(design=desgin, towel=line):
                    cnt += 1
                    # print(line)
        print("Day 19 part 1:", cnt)


def is_possible(design: dict, towel: str):
    if towel in design:
        return design[towel]

    possible = False
    lst = [k for k, v in design.items() if towel.startswith(k)
           and v and k != ""]

    for k in lst:
        possible = possible or is_possible(design, towel[len(k):])
        if possible:
            break
    design[towel] = possible

    return design[towel]


main()
