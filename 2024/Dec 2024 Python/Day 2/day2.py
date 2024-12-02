def main():

    part_one("../textfiles/day2test.txt")


def part_one(fileName):
    cnt = 0
    with open(fileName, encoding="utf8") as f:
        reports = f.readlines()
        for report in reports:
            if is_vaild(report):
                cnt += 1
        print("Day two part one answer", cnt)


def is_vaild(report):
    # split the lines
    vals = [int(x) for x in report.split()]

    # find diffrences
    diffs = []
    for i in range(len(vals)-1):
        diffs.append(vals[i]-vals[i+1])

    # if diffrences are too big
    if any(abs(diff) > 3 or diff == 0 for diff in diffs):
        return False

    for i in range(1, len(diffs)):
        if diffs[0] < 0 and diffs[i] > 0:
            return False
        if diffs[0] > 0 and diffs[i] < 0:
            return False

    return True


main()
