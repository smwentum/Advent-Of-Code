import heapq
from collections import Counter


def main():
    fileName = "../textfiles/day1.txt"
    part_one(fileName=fileName)
    part_two(fileName=fileName)


def part_one(fileName):
    l1 = []
    l2 = []
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        for line in lines:
            if len(line) > 3:
                a = int(line.split()[0])
                b = int(line.split()[1])
                l1.append(a)
                l2.append(b)

        # i am pretty sure heapify is a min heap
        heapq.heapify(l1)
        heapq.heapify(l2)
        s = 0

        while len(l1) > 0 and len(l2) > 0:
            s += abs(heapq.heappop(l1) - heapq.heappop(l2))

        print("Day One Part One answer:", s)


def part_two(fileName):
    l1 = []
    l2 = []
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        for line in lines:
            if len(line) > 3:
                a = int(line.split()[0])
                b = int(line.split()[1])
                l1.append(a)
                l2.append(b)
        count = Counter(l2)
        ans = 0
        for l in l1:
            if l in count:
                ans += l*count[l]
        print("Day One Part Two answer:", ans)


main()
