def main():

    part_one("../textfiles/day2test.txt")
    part_two("../textfiles/day2test.txt")


def part_one(fileName):
    cnt = 0
    with open(fileName, encoding="utf8") as f:
        reports = f.readlines()
        for report in reports:
            if is_vaild(report):
                cnt += 1
        print("Day two part one answer", cnt)


def part_two(fileName):
    cnt = 0
    with open(fileName, encoding="utf8") as f:
        reports = f.readlines()
        for report in reports:
            if is_vaild(report):
                cnt += 1
            elif is_vaild_with_one_removed(report):
                cnt += 1
        print("Day two part two answer", cnt)


def is_vaild_with_one_removed(report):
    # split the lines
    vals = [int(x) for x in report.split()]
    reports = get_report_with_one_removed(vals)
    # print(report)
    # print(reports)
    if any(is_valid_report_diff(report) for report in reports):
        return True

    return False


def is_valid_report_diff(vals):
    diffs = []
    for i in range(len(vals)-1):
        diffs.append(vals[i]-vals[i+1])

    if any(abs(diff) > 3 or diff == 0 for diff in diffs):
        return False

    for i in range(1, len(diffs)):
        if diffs[0] < 0 and diffs[i] > 0:
            return False
        if diffs[0] > 0 and diffs[i] < 0:
            return False

    return True


def get_report_with_one_removed(report):
    reports = []
    # reports.append(report[0])
    for i in range(0, len(report)):
        report1 = report[0:i]+report[i+1:]
        reports.append(report1)

    return reports


def is_vaild(report):
    # split the lines
    vals = [int(x) for x in report.split()]

    return is_valid_report_diff(vals)


main()
