from collections import deque


class code:
    def __init__(self, code):
        self.starting_code = code
        self.get_first_robot_key_code()

    def get_first_robot_key_code(self):
        self.keypad = [['*']*3 for _ in range(4)]
        self.keypad[0][0] = '7'
        self.keypad[0][1] = '8'
        self.keypad[0][2] = '9'
        self.keypad[1][0] = '4'
        self.keypad[1][1] = '5'
        self.keypad[1][2] = '6'
        self.keypad[2][0] = '1'
        self.keypad[2][1] = '2'
        self.keypad[2][2] = '3'
        self.keypad[3][1] = '0'
        self.keypad[3][2] = 'A'
        # self.print_first_pad()

        start = (3, 2)
        self.first_robot_key_code = ""
        for c in self.starting_code:
            start, shortestCode = self.get_next_first_robot_code(start, c)
            self.first_robot_key_code += shortestCode
        print(self.first_robot_key_code)

    def get_next_first_robot_code(self, start, c):
        parents = dict()
        dist = dict()
        for i, _ in enumerate(self.keypad):
            for j, _ in enumerate(self.keypad[i]):
                if self.keypad[i][j] == c:
                    stop = (i, j)
                # parents[(i, j)] = float('inf')
                dist[(i, j)] = float('inf')

        self.shortestPath(self.keypad, start, parents, dist)
        nextCode = self.get_shortest_path(
            self.keypad, start, stop, parents, dist)

        return stop, nextCode

    def get_shortest_path(self, graph, start, stop, parent, dist):

        if dist[stop] == float('inf'):
            return ""

        path = []
        current = stop
        path.append(current)
        s = ""
        while (parent[(current[0], current[1])][0] != start[0] and
               parent[(current[0], current[1])][1] != start[1]):
            path.append((parent[(current[0], current[1])][0],
                        parent[(current[0], current[1])][1]))
            current = (parent[(current[0], current[1])][0],
                       parent[(current[0], current[1])][1])
            s += parent[(current[0], current[1])][2]
        s += graph[start[0]][start[1]]
        for i in range(len(path) - 1, -1, -1):
            print(path[i], end=" ")
        return s

    def shortestPath(self, graph, start, parents, dist):
        que = deque([])
        dist[(start[0], start[1])] = 0
        parents[(start[0], start[1])] = (start[0], start[1], "A")
        que.append((start[0], start[1], "A"))

        while que:
            current = que.popleft()

            neighbors = self.get_neigbors(graph, current)
            for neighbor in neighbors:
                if dist[(neighbor[0], neighbor[1])] == float('inf'):
                    parents[(neighbor[0], neighbor[1])] = (
                        current[0], current[1], neighbor[2])

                    dist[(neighbor[0], neighbor[1])] = dist[(
                        current[0], current[1])] + 1
                    que.append((neighbor[0], neighbor[1], neighbor[2]))

    def get_neigbors(self, graph, current):
        directions = [(1, 0, "v"), (-1, 0, "^"), (0, 1, ">"), (0, -1, "<")]
        neighbors = []

        for direction in directions:
            newPt = (direction[0]+current[0], direction[1]+current[1])
            if self.is_valid(graph, newPt):
                neighbors.append((newPt[0], newPt[1], direction[2]))
        return neighbors

    def is_valid(self, graph, newPt):
        rows = len(graph)
        cols = len(graph[0])
        if newPt[0] < 0 or newPt[0] >= rows or newPt[1] < 0 or newPt[1] >= cols or graph[newPt[0]][newPt[1]] == "*":
            return False
        return True

    def print_first_pad(self):
        for i, _ in enumerate(self.keypad):
            for j, _ in enumerate(self.keypad[i]):
                print(self.keypad[i][j], end="")
            print()


def main():
    file_name = "../textfiles/day21test.txt"
    part_one(file_name)
    c = code("029A")


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()


main()
