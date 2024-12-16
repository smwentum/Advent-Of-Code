from collections import deque


def main():

    # file_name = "../textfiles/day16test.txt"
    # file_name = "../textfiles/day16test1.txt"
    # print("Second Test")
    # part_one(file_name)
    # print("Final")
    file_name = "../textfiles/day16final.txt"
    part_one(file_name)
    part_two(file_name=file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        grid = f.read().splitlines()
        startX = 0
        startY = 0
        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid[i]):
                if grid[i][j] == "S":
                    # print(i, j)
                    startX = i
                    startY = j
                    # break

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        min_path_cost = get_min_path_cost(
            grid, startX, startY, directions, 0)
        print("Day 16 part one:", min_path_cost)
        return min_path_cost
        # 135588 too high


def part_two(file_name):
    with open(file=file_name, encoding="utf8") as f:
        grid = f.read().splitlines()
        startX = 0
        startY = 0
        stopX = 0
        stopY = 0
        st = set()
        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid[i]):
                if grid[i][j] == "S":
                    # print(i, j)
                    startX = i
                    startY = j
                    # break
                if grid[i][j] == "E":
                    stopX = i
                    stopY = j
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        st.add((startX, startY))
        st.add((stopX, stopY))
        min_path_cost2, d_start = get_min_path_cost_pt2(
            grid, startX, startY, directions, 0, stopX, stopY)

        min_path_cost2, d_end1 = get_min_path_cost_pt2(
            grid, stopX, stopY, directions, 0, startX, startY)

        min_path_cost2, d_end2 = get_min_path_cost_pt2(
            grid, stopX, stopY, directions, 1, startX, startY)

        min_path_cost2, d_end3 = get_min_path_cost_pt2(
            grid, stopX, stopY, directions, 2, startX, startY)

        min_path_cost2, d_end4 = get_min_path_cost_pt2(
            grid, stopX, stopY, directions, 3, startX, startY)

        # print(d_end)
        print("min path cost:", min_path_cost2)
        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid[i]):
                if grid[i][j] == ".":
                    for k in range(4):
                        if ((i, j, k) in d_start
                            and (i, j, ((k+2) % 4)) in d_end1
                                and d_start[(i, j, k)] + d_end1[(i, j, ((k+2) % 4))] == min_path_cost2):
                            st.add((i, j))

                        if ((i, j, k) in d_start
                            and (i, j, ((k+2) % 4)) in d_end2
                                and d_start[(i, j, k)] + d_end2[(i, j, ((k+2) % 4))] == min_path_cost2):
                            st.add((i, j))

                        if ((i, j, k) in d_start
                            and (i, j, ((k+2) % 4)) in d_end3
                                and d_start[(i, j, k)] + d_end3[(i, j, ((k+2) % 4))] == min_path_cost2):
                            st.add((i, j))

                        if ((i, j, k) in d_start
                            and (i, j, ((k+2) % 4)) in d_end4
                                and d_start[(i, j, k)] + d_end4[(i, j, ((k+2) % 4))] == min_path_cost2):
                            st.add((i, j))

                    # startToPoint = get_min_path_cost_pt2(
                    #     grid, startX, startY, directions, 0, i, j)

                    # pointToEnd = min(get_min_path_cost_pt2(
                    #     grid, i, j, directions, 0, stopX, stopY),
                    #     get_min_path_cost_pt2(
                    #     grid, i, j, directions, 1, stopX, stopY),
                    #     get_min_path_cost_pt2(
                    #     grid, i, j, directions, 2, stopX, stopY),
                    #     get_min_path_cost_pt2(
                    #     grid, i, j, directions, 3, stopX, stopY))
                    # for i1 in range(4):
                    #     if startToPoint + get_min_path_cost_pt2(
                    #             grid, i, j, directions, i1, stopX, stopY) == min_path_cost2:
                    #         st.add((i, j))

        print("Day 16 part 2", len(st))


def get_min_path_cost(grid, currX, currY, directions, currentDirection):

    d = dict()

    max_value = 10**300
    cost = max_value
    que = deque([(currX, currY, currentDirection, 0)])

    while len(que) > 0:
        current = que.popleft()
        if ((current[0], current[1], current[2]) not in d
                or (d[(current[0], current[1], current[2])] > current[3]
                    and d[(current[0], current[1], current[2])] != max_value
                    )):

            if grid[current[0]][current[1]] == "#":
                d[current[0], current[1], current[2]] = max_value
                # d[current[0], current[1], 1] = max_value
                # d[current[0], current[1], 2] = max_value
                # d[current[0], current[1], 3] = max_value

            elif grid[current[0]][current[1]] == "E":
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
                           ((current[2]+1) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+3) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+2) % 4), 1000+current[3]))

                d[(current[0], current[1], current[2])] = current[3]
                # print(cost)
    # for k, v in d.items():
    #     if (v != max_value):
    #         print(k, v)
    return cost


def get_min_path_cost3(grid, currX, currY, directions, currentDirection):

    d = dict()

    max_value = 10**300
    cost = max_value
    que = deque([(currX, currY, currentDirection, 0)])

    d2 = dict()

    while len(que) > 0:
        current = que.popleft()
        if ((current[0], current[1], current[2]) not in d
                or (d[(current[0], current[1], current[2])] > current[3]
                    and d[(current[0], current[1], current[2])] != max_value
                    )):

            if grid[current[0]][current[1]] == "#":
                d[current[0], current[1], current[2]] = max_value
                # d[current[0], current[1], 1] = max_value
                # d[current[0], current[1], 2] = max_value
                # d[current[0], current[1], 3] = max_value

            elif grid[current[0]][current[1]] == "E":
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
                           ((current[2]+1) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+3) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+2) % 4), 1000+current[3]))

                d[(current[0], current[1], current[2])] = current[3]
                # print(cost)
    # for k, v in d.items():
    #     if (v != max_value):
    #         print(k, v)
    return cost


def get_min_path_cost_pt2(grid, currX, currY, directions, currentDirection, stopX, stopY):

    d = dict()

    max_value = 10**300
    cost = max_value
    que = deque([(currX, currY, currentDirection, 0)])

    while len(que) > 0:
        current = que.popleft()
        if ((current[0], current[1], current[2]) not in d
                or (d[(current[0], current[1], current[2])] >= current[3]
                    and d[(current[0], current[1], current[2])] != max_value
                    )):

            if grid[current[0]][current[1]] == "#":
                d[current[0], current[1], current[2]] = max_value
                # d[current[0], current[1], 1] = max_value
                # d[current[0], current[1], 2] = max_value
                # d[current[0], current[1], 3] = max_value

            elif current[0] == stopX and current[1] == stopY:
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
                           ((current[2]+1) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+3) % 4), 1000+current[3]))
                que.append((current[0], current[1],
                           ((current[2]+2) % 4), 1000+current[3]))

                d[(current[0], current[1], current[2])] = current[3]
                # print(cost)
    d1 = dict()
    for k, v in d.items():
        if (v != max_value):
            d1[k] = v

    return cost, d1


main()
