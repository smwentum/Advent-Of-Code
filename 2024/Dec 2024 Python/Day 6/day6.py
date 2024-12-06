def main():
    fileName = "../textfiles/day6final.txt"
    part_one(file_name=fileName)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        grid = f.read().splitlines()
        # find the staring position
        startX = 0
        startY = 0
        startDirection = (-1, 0)
        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid):
                if grid[i][j] == '^':
                    startX = i
                    startY = j
        visitedPoints = set()
        visitedPoints.add((startX, startY))

        while True:
            # i need to figure out where to go next
            if isValidInGrid(startX+startDirection[0], startY+startDirection[1], len(grid), len(grid[0])):
                if grid[startX+startDirection[0]][startY+startDirection[1]] != "#":
                    startX = startX+startDirection[0]
                    startY = startY+startDirection[1]
                    visitedPoints.add((startX, startY))
                else:
                    startDirection = changeDirection(startDirection)
                # print(startX, startY)
            else:
                break

        print("Day 6 part One:", len(visitedPoints))


def isValidInGrid(x, y, maxRow, maxCol):
    if x < 0 or x >= maxRow or y < 0 or y >= maxCol:
        return False
    return True


def changeDirection(v):
    # up
    if v[0] == -1 and v[1] == 0:
        return (0, 1)

    # right
    if v[0] == 0 and v[1] == 1:
        return (1, 0)
    # down
    if v[0] == 1 and v[1] == 0:
        return (0, -1)
    # left
    if v[0] == 0 and v[1] == -1:
        return (-1, 0)


main()
