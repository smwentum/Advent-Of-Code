import copy


def main():

    file_name = "../textfiles/day7final.txt"
    part_one(file_name)


def part_one(file_name):
    # get the lines

    with open(file_name, encoding="utf8") as f:
        cnt = 0
        lines = f.read().splitlines()
        for line in lines:
            cnt += isEquationPossible(line)

        print("Day 7 Part 1:", cnt)


def isEquationPossible(line):
    result = int(line.split(":")[0])
    # print(result)
    remaining_numbers = [int(x) for x in line.split(":")[1].strip().split(" ")]
    # print(remaining_numbers)
    if foundResult(result, remaining_numbers, 0):
        return result
    return 0


def foundResult(result, remaining_numbers, currentValue):
    # print(currentValue, "\n")
    # print("remaing numbers", remaining_numbers)
    if currentValue > result:
        return False
    if currentValue != 0:
        remaining_numbers.insert(0, currentValue)
    # print("remaing numbers", remaining_numbers)
    if len(remaining_numbers) == 1:
        # print("about to stop")
        # print("about to stop:", result, remaining_numbers[0])
        return result == remaining_numbers[0]
    if len(remaining_numbers) == 0:
        return False
    a = remaining_numbers.pop(0)
    b = remaining_numbers.pop(0)
    # print(a, b)
    x1 = copy.deepcopy(remaining_numbers)
    x2 = copy.deepcopy(remaining_numbers)
    if currentValue == 0:
        return (foundResult(result, x1, a*b)
                or foundResult(result, x2, a+b))
    return (foundResult(result, copy.deepcopy(remaining_numbers), currentValue*b)
            or foundResult(result, copy.deepcopy(remaining_numbers), currentValue+b))


main()
