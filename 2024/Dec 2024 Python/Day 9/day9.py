def main():
    filename = "../textfiles/day9final.txt"
    part_one(filename)


def part_one(filename):

    with open(file=filename, encoding="utf8") as f:
        line = f.readline()
        print(line)
        decompated = []
        index = 0
        isFreeSpace = False
        for i in range(len(line)):
            number_of_times = int(line[i])
            # print(number_of_times)
            if not isFreeSpace:
                for _ in range(number_of_times):
                    decompated.append(index)
                index += 1
            else:
                for _ in range(number_of_times):
                    decompated.append(-1)
            isFreeSpace = not isFreeSpace
        # print(decompated)
        left = 0
        right = len(decompated)-1
        while left < right:
            # print(left, right)
            while left < len(decompated) and decompated[left] != -1:
                left += 1
            while right > -1 and decompated[right] == -1:
                right -= 1
            if (left < len(decompated) and decompated[left] == -1 and right > -1 and decompated[right] != -1):
                decompated[left] = decompated[right]
                decompated[right] = -1
                left += 1
                right -= 1
        # print(decompated)
        print("Day 9 part One:", getCheckSum(decompated))


def getCheckSum(decompated):
    s = 0
    for i, val in enumerate(decompated):
        # print(val, i)
        if val != -1:
            s += i*val

        else:
            break
    return s


main()
