from collections import deque


def main():

    #file_name = "../textfiles/day18test.txt"
    #part_one(file_name,7,7,12)
    file_name = "../textfiles/day18final.txt"
    part_one(file_name,71,71,1024)



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
        part_oneA(grid,rows)


def part_oneA(grid,rows):

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

        print("Day 18 part one:", min_path_cost)
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





        #printGrid(grid)

# def Dijkstra(grid, source,rows,cols):
#     dist = dict()
#     prev = dict()
#     dir = [(1,0),(-1,0),(0,1)(0,-1)]
#     for r in len(rows):
#         for c in len(cols):
#             dist[(r,c)] = 2 ** 100
#             prev[(r,c)] = 2** 100
#     dist[source] = 0
#     q = heapq.heapify([source[0],source[1],0])

#     while len(q) > 0 :
#         current = heapq.heappop(q)


# def dijkstra(self, start_vertex_data,rows):
#     start_vertex = self.vertex_data.index(start_vertex_data)
#     distances = [float('inf')] * self.size
#     for i in range(rows):
#         for j in range(rows):
#              j
#     distances[start_vertex] = 0
#     visited = [False] * self.size

#     for _ in range(self.size):
#         min_distance = float('inf')
#         u = None
#         for i in range(self.size):
#             if not visited[i] and distances[i] < min_distance:
#                 min_distance = distances[i]
#                 u = i

#         if u is None:
#             break

#         visited[u] = True

#         for v in range(self.size):
#             if self.adj_matrix[u][v] != 0 and not visited[v]:
#                 alt = distances[u] + self.adj_matrix[u][v]
#                 if alt < distances[v]:
#                     distances[v] = alt

#     return distances

#  1  function Dijkstra(Graph, source):
#  2
#  3      for each vertex v in Graph.Vertices:
#  4          dist[v] ← INFINITY
#  5          prev[v] ← UNDEFINED
#  6          add v to Q
#  7      dist[source] ← 0
#  8
#  9      while Q is not empty:
# 10          u ← vertex in Q with minimum dist[u]
# 11          remove u from Q
# 12
# 13          for each neighbor v of u still in Q:
# 14              alt ← dist[u] + Graph.Edges(u, v)
# 15              if alt < dist[v]:
# 16                  dist[v] ← alt
# 17                  prev[v] ← u
# 18
# 19      return dist[], prev[]

def printGrid(grid):
    for i,_ in enumerate(grid):
        for j,_ in enumerate(grid[i]):
            print(grid[i][j],end=" ")
        print()


main()