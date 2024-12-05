def main():

    fileName = "../textfiles/day5final.txt"

    part_one(fileName)


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


main()
