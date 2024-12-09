def main():

    file_name = "../textfiles/day8final.txt"
    part_one(file_name)
    file_name = "../textfiles/day8final.txt"
    part_two(file_name)


def part_one(file_name):
    # get the lines

    with open(file_name, encoding="utf8") as f:
        cnt = 0
        lines = f.read().splitlines()
        rows = len(lines)
        cols = len(lines[0])
        d = dict()
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[i]):
                # make a dict of chars (not the dots) and put each point as tuple
                if lines[i][j] != '.':
                    if lines[i][j] not in d:
                        d[lines[i][j]] = set()

                    d[lines[i][j]].add((i, j))
        # now that i have the points add the antinotes
        setOfNodes = set()
        for group in d:

            # print("\n", d[group])
            lst = list(d[group])
            # print(lst)
            # print(len(lst)-1)
            for i in range(len(lst)):
                for j in range(i+1, len(lst)):
                    # print(i)
                    pt1 = lst[i]
                    pt2 = lst[j]
                    # print(pt1)
                    # print(pt2)
                    xDist = pt1[0]-pt2[0]
                    yDist = pt1[1]-pt2[1]
                    pt3 = ((pt1[0]-xDist), (pt1[1]-yDist))
                    if pt3 == pt2:
                        pt3 = ((pt1[0]+xDist), (pt1[1]+yDist))

                    pt4 = ((pt2[0]+xDist), (pt2[1]+yDist))
                    if pt4 == pt1:
                        pt4 = ((pt2[0]-xDist), (pt2[1]-yDist))
                    # print(pt3)
                    # print(pt4)

                    if isValidPoint(pt3, rows, cols) and pt3 not in setOfNodes:
                        setOfNodes.add(pt3)

                    if isValidPoint(pt4, rows, cols) and pt4 not in setOfNodes:
                        setOfNodes.add(pt4)

        print("Day Eight Part One:", len(setOfNodes))


def part_two(file_name):
    # get the lines

    with open(file_name, encoding="utf8") as f:
        cnt = 0
        lines = f.read().splitlines()
        rows = len(lines)
        cols = len(lines[0])
        d = dict()
        nonemptySpot = []
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[i]):
                # make a dict of chars (not the dots) and put each point as tuple
                if lines[i][j] != '.':
                    if lines[i][j] not in d:
                        d[lines[i][j]] = set()
                    nonemptySpot.append((i, j))
                    d[lines[i][j]].add((i, j))

        # now that i have the points add the antinotes
        setOfNodes = set()
        lst1 = []
        for group in d:
            lst = list(d[group])
            for i in range(len(lst)):
                for j in range(i+1, len(lst)):
                    # print(i)
                    pt1 = lst[i]
                    pt2 = lst[j]
                    # print(pt1)
                    # print(pt2)

                    xDist = pt1[0]-pt2[0]
                    yDist = pt1[1]-pt2[1]

                    pt3 = ((pt1[0]-xDist), (pt1[1]-yDist))
                    if pt3 == pt2:
                        pt3 = ((pt1[0]+xDist), (pt1[1]+yDist))
                        i1 = 2
                        while isValidPoint(pt3, rows, cols):
                            lst1.append(pt3)
                            pt3 = ((pt1[0]+i1*xDist), (pt1[1]+i1*yDist))
                            # print(pt3)
                            i1 += 1

                    else:
                        i1 = 2
                        while isValidPoint(pt3, rows, cols):
                            lst1.append(pt3)
                            pt3 = ((pt1[0]-i1*xDist), (pt1[1]-i1*yDist))
                            i1 += 1

                    pt4 = ((pt2[0]+xDist), (pt2[1]+yDist))
                    if pt4 == pt1:
                        pt4 = ((pt2[0]-xDist), (pt2[1]-yDist))
                        i1 = 2
                        while isValidPoint(pt4, rows, cols):
                            lst1.append(pt4)
                            pt4 = ((pt2[0]-i1*xDist), (pt2[1]-i1*yDist))
                            i1 += 1
                    else:
                        i1 = 2
                        while isValidPoint(pt4, rows, cols):
                            lst1.append(pt4)
                            pt4 = ((pt2[0]+i1*xDist), (pt2[1]+i1*yDist))
                            i1 += 1

            for l1 in lst1:
                if isValidPoint(l1, rows, cols) and l1 not in setOfNodes:
                    setOfNodes.add(l1)
        # print(lst1)
       # print("Day Eight Part Two:", len(setOfNodes))
        # print("Day Eight Part Two:", len(setOfNodes)+nonemptySpot)
        print("Day Eight Part Two:", len(setOfNodes.union(nonemptySpot)))


def isValidPoint(pt, rows, cols):
    x = pt[0]
    y = pt[1]

    if x < 0 or x >= rows or y < 0 or y >= cols:
        return False
    return True


main()
