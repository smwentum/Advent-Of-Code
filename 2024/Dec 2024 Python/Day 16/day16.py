def main():

    file_name = "../textfiles/day16test1.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        grid = f.read().splitlines()
        startX = 0
        startY = 0
        rows = len(grid)
        cols = len(grid[0])  # assuming rectangular grid

        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid[i]):
                if grid[i][j] == "S":
                    print(i, j)
                    startX = i
                    startY = j
                    break
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        min_path_cost = get_min_path_cost(grid, startX, startY, directions, 1)
        print("Day 16 part one:", min_path_cost)


def get_min_path_cost(grid, currX, currY, directions, currentDirection):

    d = dict()

    max_value = 10**300
    cost = max_value
    que = [(currX, currY, currentDirection, 0)]
    while len(que) > 0:
        current = que.pop()
        if ((current[0], current[1], current[2]) not in d
                or d[(current[0], current[1], current[2])] > current[3]):

            if grid[current[0]][current[1]] == "#":
                d[current[0], current[1], 0] = max_value
                d[current[0], current[1], 1] = max_value
                d[current[0], current[1], 2] = max_value
                d[current[0], current[1], 3] = max_value

            elif grid[current[0]][current[1]] == "E":
                print(current[3])
                cost = min(cost, current[3])
            else:  # grid[current[0]][current[1]] == '.' || :
                # go in current direction
                que.append((current[0]+directions[current[2]][0],
                            current[1] + directions[current[2]][1],
                            current[2],
                            1+current[3]))

                que.append((current[0], current[1],
                           (current[2]+1) % 4, 1000+current[3]))
                que.append((current[0], current[1],
                           (current[2]+3) % 4, 1000+current[3]))
                que.append((current[0], current[1],
                           (current[2]+2) % 4, 1000+current[3]))

                d[(current[0], current[1], current[2])] = current[3]
                # print(cost)
    for k, v in d.items():
        if (v != max_value):
            print(k, v)
    return cost


main()
