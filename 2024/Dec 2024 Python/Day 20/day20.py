from collections import deque


def main():
    file_name = "../textfiles/day20final.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        rows = len(lines)
        cols = len(lines[0])
        racetrack = [["#"]*cols for _ in range(rows)]
        startX = 0
        startY = 0
        endX = 0
        endY = 0
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[0]):
                if lines[i][j] != '#':
                    racetrack[i][j] = lines[i][j]
                if lines[i][j] == "S":
                    # print_track(racetrack=racetrack)
                    startX = i
                    startY = j
                if lines[i][j] == "E":
                    endX = i
                    endY = j
        maxTimeOfRace = getShortestPath(
            racetrack, (startX, startY), (endX, endY), (rows, cols))
        cheats = getCheats(racetrack, (rows, cols),
                           (startX, startY), maxTimeOfRace)
        timesSaved = dict()

        # print(maxTimeOfRace)
        # print(cheats)
        for cheat in cheats:
            racetrack[cheat[0]][cheat[1]] = '.'
            timeSaved = maxTimeOfRace - getShortestPath(
                racetrack, (startX, startY), (endX, endY), (rows, cols))
            if timeSaved not in timesSaved:
                timesSaved[timeSaved] = 0
            timesSaved[timeSaved] += 1
            racetrack[cheat[0]][cheat[1]] = '#'

        s = 0
        for k, v in timesSaved.items():
            if k >= 100:
                s += v
        print("day 20 part one:", s)
        # 1264 too low


def getCheats(racetrack, dim, start, mindistance):
    cheats = set()
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for i, _ in enumerate(racetrack):
        for j, _ in enumerate(racetrack):
            if i > 0 and j > 0 and i < dim[0]-1 and j < dim[1]-1:
                if racetrack[i][j] == "#":
                    for d in directions:
                        neighbor = (i+d[0], j+d[1])
                        if isVaildPoint(neighbor, dim) and racetrack[neighbor[0]][neighbor[1]] == ".":
                            if abs(i-start[0]) + abs(j-start[1]) < mindistance:
                                cheats.add((i, j))
                                break

    return cheats


def getShortestPath(raceTrack, start, end, dim):
    max_value = 10**30

    que = deque([])
    dist = dict()
    que.append(start)
    for i in range(dim[0]):
        for j in range(dim[1]):
            dist[(i, j)] = max_value

    dist[start] = 0

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    while (len(que)) > 0:
        current = que.popleft()
        for d in directions:
            neighbor = (current[0]+d[0], current[1]+d[1])
            if isVaildPoint(neighbor, dim) and dist[neighbor] == max_value and raceTrack[neighbor[0]][neighbor[1]] != "#":
                dist[neighbor] = dist[current]+1
                que.append(neighbor)
    return dist[end]


def isVaildPoint(pt, dim):
    return not (pt[0] < 0 or pt[0] >= dim[0]
                or pt[1] < 0 or pt[0] >= dim[1])


def print_track(racetrack):
    for i, _ in enumerate(racetrack):
        for j, _ in enumerate(racetrack[0]):
            print(racetrack[i][j], end=" ")
        print()


main()
