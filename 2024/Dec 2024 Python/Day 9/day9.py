def main():
    filename = "../textfiles/day9final.txt"
    part_one(filename)


def part_one(filename):

    with open(file=filename, encoding="utf8") as f:
        line = f.readline()
        # print(line)
        decompated = []
        index = 0

        for i,_ in enumerate(line):
            number_of_times = int(line[i])
            # print(number_of_times)
            if i%2 == 0:
                decompated+=[index]*number_of_times
                index += 1
            else:
                decompated+=[-1]*number_of_times

        print(decompated)
        blanks = [i for i,x in enumerate(decompated) if x == -1]

        print("blanks",blanks)
        for i in blanks:
            #remove the blanks at the end
            while decompated[-1] == -1:
                decompated.pop()
            if len(decompated) <= i:
                    break
            decompated[i]=decompated.pop()
        print(decompated)
        # left = 0
        # right = len(decompated)-1
        # while left < right:
        #     # print(left, right)
        #     while left < len(decompated) and decompated[left] != -1:
        #         left += 1
        #     while right > -1 and decompated[right] == -1:
        #         right -= 1

        #     if (left < len(decompated) and decompated[left] == -1 and right > -1 and decompated[right] != -1):
        #         decompated[left] = decompated[right]
        #         decompated[right] = -1
        #         left += 1
        #         right -= 1
        # # print(decompated)
        print("Day 9 part One:", getCheckSum(decompated))
        # 6334393041104 -too low
        # 6334655984939


def getCheckSum(decompated):
    s = 0
    for i, val in enumerate(decompated):
        # print(val, i)
        if val != -1:
            s += i*val
    return s


main()
