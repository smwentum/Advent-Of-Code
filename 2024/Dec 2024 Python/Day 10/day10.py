def main():
    fileName = "../textfiles/day10final.txt"
    part_one(fileName=fileName)
    fileName = "../textfiles/day10final.txt"
    part_two(fileName=fileName)


def part_one(fileName):

    with open(file=fileName, encoding="utf8") as f:
        # i am going to leave this a list of strings becasue why not
        lines = f.read().splitlines()
        trailheads = []
        s = 0
        for i, _ in enumerate(lines):
            for j, val in enumerate(lines[i]):
                if int(val) == 0:
                    trailheads.append((i, j))
        for trailhead in trailheads:

            s += get_number_of_trails(lines, trailhead)

        print("Day ten part one:", s)


def part_two(fileName):

    with open(file=fileName, encoding="utf8") as f:
        # i am going to leave this a list of strings becasue why not
        lines = f.read().splitlines()
        trailheads = []
        s = 0
        for i, _ in enumerate(lines):
            for j, val in enumerate(lines[i]):
                if int(val) == 0:
                    trailheads.append((i, j))
        for trailhead in trailheads:

            s += get_number_of_trailsPt2(lines, trailhead)

        print("Day ten part two:", s)


def get_number_of_trails(lines, trailhead):
    s = 0
    st = set()
    que = []
    que.append((trailhead[0], trailhead[1], 0))
    rows = len(lines)
    cols = len(lines[0])
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while len(que) > 0:
        current = que.pop()
        # print(current)
        if current[2] == 9 and (current[0], current[1]) not in st:
            s += 1
            st.add((current[0], current[1]))
        else:
            # get all points around with value of current[2]+1
            for d in directions:
                newPt = current[0]+d[0], current[1]+d[1]
                # print("current", current, "newpt", newPt)
                if is_valid_point(newPt, rows, cols) and int(lines[newPt[0]][newPt[1]]) == current[2]+1:
                    que.append((newPt[0], newPt[1], current[2]+1))
    # print("trailhead:", trailhead, "sum:", s)

    return s


def get_number_of_trailsPt2(lines, trailhead):
    s = 0
    st = set()
    que = []
    que.append((trailhead[0], trailhead[1], 0))
    rows = len(lines)
    cols = len(lines[0])
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while len(que) > 0:
        current = que.pop()
        # print(current)
        if current[2] == 9:
            s += 1

        else:
            # get all points around with value of current[2]+1
            for d in directions:
                newPt = current[0]+d[0], current[1]+d[1]
                # print("current", current, "newpt", newPt)
                if is_valid_point(newPt, rows, cols) and int(lines[newPt[0]][newPt[1]]) == current[2]+1:
                    que.append((newPt[0], newPt[1], current[2]+1))
    # print("trailhead:", trailhead, "sum:", s)

    return s


def is_valid_point(newPt, rows, cols):

    x = newPt[0]
    y = newPt[1]
    if x < 0 or x >= rows or y < 0 or y >= cols:
        return False
    return True


main()
