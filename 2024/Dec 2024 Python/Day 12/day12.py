def main():

    file_name = "../textfiles/day12final.txt"
    part_one(file_name)
    file_name = "../textfiles/day12final.txt"
    part_two(file_name=file_name)


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
        #print(groups_of_plants)
        s = 0
        for i,value in groups_of_plants.items():
            area = len(value)
            perimeter = getPerimeter(value)
            #print(i,area,perimeter)
            s+= area*perimeter
        print("Day 12 part 1",s )

def part_two(file_name):
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
        # print(groups_of_plants)
        s = 0
        for i,value in groups_of_plants.items():
            #print(i)
            area = len(value)
            #print(value)
            perimeter = getCorner(value)
            #print(i,area,perimeter)
            s+= area*perimeter
        print("Day 12 part 2",s )


def getPerimeter(lst):
    st = set(lst)
    dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    cnt =0
    for d in dir:
        for s in st:
            if  (s[0]+d[0],s[1]+d[1])not in st:
                cnt+=1
    return cnt

def getCorner(lst):
    st = set(lst)
    dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    # print(dir)
    cnt =0
    for s in lst:
        for i in range(len(dir)):
            for j in range(i+1,len(dir)):
                if not (dir[i][0] ==dir[j][0] or dir[i][1] ==dir[j][1]):
                    #print(dir[i],dir[j])
                    newPt1 = (s[0]+dir[i][0],s[1]+dir[i][1])
                    newPt2 = (s[0]+dir[j][0],s[1]+dir[j][1])
                    newPt3 = (s[0]+dir[i][0]+dir[j][0],s[1]+dir[j][1]+dir[i][1])
                    firstPointIn = newPt1 in st
                    secondPointIn =  newPt2 in st
                    thirdPointIn = newPt3 in st
                    if  ( ( firstPointIn and secondPointIn and (not thirdPointIn))  or
                          ((not firstPointIn) and (not secondPointIn)) ):
                        #print(s,dir[i],dir[j],newPt1,newPt2)
                        cnt+=1
    return cnt



def explore_all_connected_points(grid, i, j, st):
    # print(i, j)
    lst = []
    vegType = grid[i][j]
    que = [(i, j)]
    rows = len(grid)
    cols = len(grid[0])
    while len(que) > 0:
        current = que.pop()
        if current not in st:
            st.add((current[0], current[1]))
            lst.append((current[0], current[1]))
            neigbors = get_valid_neighbors(current[0], current[1], rows, cols)
            #print("neigbors", neigbors)
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
