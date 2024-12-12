def main():

    file_name = "../textfiles/day12test1.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        grid = f.read().splitlines()
        # a set of char tuples (1, (0,0) (0,1)) i cant use letter because their can be distinct separte plots
        groups_of_plants = dict()
        st = set()  # the places i have visted
        group_of_plants_count = 1
        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid):
                if (i, j) not in st:
                    lst, st = explore_all_connected_points(grid, i, j, st)
                    groups_of_plants[group_of_plants_count] = lst
                    group_of_plants_count += 1
        print(groups_of_plants)


def explore_all_connected_points(grid, i, j, st):
    # print(i, j)
    lst = []
    vegType = grid[i][j]
    que = [(i, j)]
    rows = len(grid)
    cols = len(grid[0])
    while len(que) > 0:
        current = que.pop()
        st.add((current[0], current[1]))
        lst.append((current[0], current[1]))
        neigbors = get_valid_neighbors(current[0], current[1], rows, cols)
        print("neigbors", neigbors)
        for neighbor in neigbors:
            if neighbor not in st and grid[neighbor[0]][neighbor[1]] == vegType:
                que.append(neighbor)
    return (lst, st)


def get_valid_neighbors(i, j, rows, cols):

    lst = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    lst1 = []
    for l in lst:
        newPt = (i+l[0], j+l[1])
        if not (newPt[0] < 0 or newPt[0] >= rows or newPt[1] < 0 or newPt[1] >= cols):
            lst1.append(newPt)
    return lst1


main()
