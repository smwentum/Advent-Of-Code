from collections import deque


def main():

    #file_name = "../textfiles/day18test.txt"
    #part_one(file_name,7,7,12)
    file_name = "../textfiles/day18final.txt"
    part_one(file_name,71,71,1024)
    file_name = "../textfiles/day18final.txt"
    part_two(file_name,71,71)



def part_one(file_name, rows,cols,stop):
    with open(file=file_name,encoding="utf8") as f:
        grid = [["."]*cols for _ in range(rows)]
        #printGrid(grid)
        lines = f.read().splitlines()
        for i, line in enumerate(lines):
            if i < stop:
                x,y = [int(z) for z in line.split(",")]
                #print(x,y)
                grid[y][x] = "#"
        #printGrid(grid)
        part_oneA(grid,rows,stop)

def part_two(file_name, rows,cols):
    with open(file=file_name,encoding="utf8") as f:
        lines = f.read().splitlines()
        low =0
        high = len(lines)-1
        #while high > low:
        grid = [["."]*cols for _ in range(rows)]
        mid =2991 # int((high +low)/2)
        for i, line in enumerate(lines):
            if i <mid:
                x,y = [int(z) for z in line.split(",")]
                grid[y][x] = "#"
        value =   part_oneA(grid,rows,mid)
        print(value)
        if (value  !=  10**300):
            low = int((high +mid)/2)+1
            print(mid)
        else:
            high =int( (low +mid)/2)-1
        grid = [["."]*cols for _ in range(rows)]





def part_oneA(grid,rows,stop):

        startX = 0
        startY = 0

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        min_path_cost = min(get_min_path_cost(
            grid, startX, startY, directions, 0,rows),
            get_min_path_cost(
            grid, startX, startY, directions, 1,rows),
            get_min_path_cost(
            grid, startX, startY, directions, 2,rows),
            get_min_path_cost(
            grid, startX, startY, directions, 3,rows))


        print("Day 18 part two:", stop, "cost:", min_path_cost)
        return min_path_cost
        # 135588 too high


def get_min_path_cost(grid, currX, currY, directions, currentDirection,rows):

    d = dict()

    max_value = 10**300
    cost = max_value
    que = deque([(currX, currY, currentDirection, 0)])

    while len(que) > 0:
        current = que.popleft()
        if (current[0] < 0 or current[0] >= rows
                or     current[1] < 0 or current[1] >= rows):
                continue
        if ((current[0], current[1], current[2]) not in d
                or (d[(current[0], current[1], current[2])] > current[3]
                    and d[(current[0], current[1], current[2])] != max_value
                    )):


            if grid[current[0]][current[1]] == "#":
                d[current[0], current[1], current[2]] = max_value
                # d[current[0], current[1], 1] = max_value
                # d[current[0], current[1], 2] = max_value
                # d[current[0], current[1], 3] = max_value

            elif current[0] == rows-1 and current[1] == rows-1:
                # if current[3] < cost:
                # print(current[3])
                cost = min(cost, current[3])
            else:  # grid[current[0]][current[1]] == '.' || :
                # go in current direction
                que.append((current[0]+directions[current[2]][0],
                            current[1]+directions[current[2]][1],
                            current[2],
                            1+current[3]))

                que.append((current[0], current[1],
                           ((current[2]+1) % 4), current[3]))
                que.append((current[0], current[1],
                           ((current[2]+3) % 4), current[3]))
                que.append((current[0], current[1],
                           ((current[2]+2) % 4), current[3]))

                d[(current[0], current[1], current[2])] = current[3]
                # print(cost)
    # for k, v in d.items():
    #     if (v != max_value):
    #         print(k, v)
    return cost






def printGrid(grid):
    for i,_ in enumerate(grid):
        for j,_ in enumerate(grid[i]):
            print(grid[i][j],end=" ")
        print()


main()