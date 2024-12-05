def main():

    fileName = "../textfiles/day5final.txt"

    part_one(fileName)

    fileName = "../textfiles/day5final.txt"

    part_two(fileName)


def part_one(fileName):
    d = dict()
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        first_part = True
        cnt = 0
        for line in lines:
            if first_part and (line.isspace() or len(line) == 0):
                first_part = False
                continue
            if first_part:
                k = int(line.split("|")[0])
                v = int(line.split("|")[1])
                if k in d:
                    d[k].add(v)
                else:
                    d[k] = set()
                    d[k].add(v)
            else:
                nums = [int(x) for x in line.split(",")]
                # print(nums)
                stop = False
                numberOfMatches = 0
                for i, x in enumerate(nums):
                    if stop:
                        break
                    # print(i)
                    for _, y in enumerate(nums[i+1:]):
                        # print(x, y)
                        if x in d and y in d[x]:
                            numberOfMatches += 1
                        elif y in d and x in d[y]:
                            stop = True
                            break
                # print(numberOfMatches)
                if numberOfMatches == (len(nums)-1)*(len(nums))/2:
                    cnt += nums[int(len(nums)/2)]

        print("Day 5 part one", cnt)


def part_two(fileName):
    d = dict()
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        first_part = True
        cnt = 0
        for line in lines:
            if first_part and (line.isspace() or len(line) == 0):
                first_part = False
                continue
            if first_part:
                k = int(line.split("|")[0])
                v = int(line.split("|")[1])
                if k in d:
                    d[k].add(v)
                else:
                    d[k] = set()
                    d[k].add(v)
            else:
                nums = [int(x) for x in line.split(",")]
                # print(nums)
                stop = False
                numberOfMatches = 0
                for i, x in enumerate(nums):
                    if stop:
                        break
                    # print(i)
                    for _, y in enumerate(nums[i+1:]):
                        # print(x, y)
                        if x in d and y in d[x]:
                            numberOfMatches += 1
                        elif y in d and x in d[y]:
                            stop = True
                            break
                # print(numberOfMatches)
                if numberOfMatches < (len(nums)-1)*(len(nums))/2:
                    cnt += getCorrectOrdering(d, nums)
                    # print(cnt)

        print("Day 5 part two", cnt)


def getCorrectOrdering(d, nums):

    # print(nums)

    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] in d and nums[j] in d[nums[i]]:
                continue
            elif nums[j] in d and nums[i] in d[nums[j]]:
                # print(nums[i], nums[j])
                temp = nums[i]

                nums[i] = nums[j]
                nums[j] = temp
                # print("after change", nums)
                return getCorrectOrdering(d, nums)

    return nums[int(len(nums)/2)]


main()
