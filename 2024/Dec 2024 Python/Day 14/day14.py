class Data:
    def __init__(self, fileName, rows1, cols1):
        self.fileName = fileName
        self.rows = rows1
        self.cols = cols1
        self.robots = []
        # print(self.rows)
        with open(file=self.fileName, encoding="utf8") as f:
            lines = f.read().splitlines()
            # print("Number of robots", len(lines))
            for line in lines:

                row, col = [int(x) for x in line.split()[
                    0].split("=")[1].split(",")]

                velX, velY = [int(x) for x in line.split()[
                    1].split("=")[1].split(",")]

                self.robots.append(
                    Robot(inti_x=col, inti_y=row, vel_x=velY, vel_y=velX, rows=self.rows, cols=self.cols))

    def getCurrentPostionOfRobotsAfterSeconds(self, secs):
        d = dict()
        for robot in self.robots:
            # print(robot)
            currPos = Robot.currentAfterSecs(robot, secs)
            if currPos not in d:
                d[currPos] = 0
            d[currPos] += 1
        return d


class Robot:
    def __init__(self, inti_x, inti_y, vel_x, vel_y, rows, cols):

        self.inti_x = inti_x
        self.inti_y = inti_y
        self.vel_x = vel_x
        self.vel_y = vel_y
        self.rows = rows
        self.cols = cols

    def __str__(self):
        return f"x:{self.inti_x} y:{self.inti_y} velx:{self.vel_x} vely:{self.vel_y}, rows:{self.rows} cols:{self.cols} "

    def currentAfterSecs(self, sec):

        return (((self.inti_x + sec*self.vel_x) % self.rows),
                ((self.inti_y + sec*self.vel_y) % self.cols))


def main():
    # fileName = "../textfiles/day14test.txt"
    # rows = 7
    # cols = 11
    # data = Data(fileName=fileName, rows1=rows, cols1=cols)
    fileName = "../textfiles/day14final.txt"
    rows = 103
    cols = 101
    data = Data(fileName=fileName, rows1=rows, cols1=cols)
    d = data.getCurrentPostionOfRobotsAfterSeconds(100)
    q1 = 0
    q2 = 0
    q3 = 0
    q4 = 0
    # print(d)
    # printGrid(d, rows, cols)
    for k, v in d.items():
        if k[0] < int(rows/2) and k[1] < int(cols/2):
            q1 += v
        if k[0] < int(rows/2) and k[1] > int(cols/2):
            q2 += v
        if k[0] > int(rows/2) and k[1] < int(cols/2):
            q3 += v
        if k[0] > int(rows/2) and k[1] > int(cols/2):
            q4 += v
    # print(q1, q2, q3, q4)
    print("Answer to Day 14 part 1:", q1*q2*q3*q4)
    fileName = "../textfiles/day14final.txt"
    rows = 103
    cols = 101
    data = Data(fileName=fileName, rows1=rows, cols1=cols)
    


def printGrid(d, rows, cols):
    lines = [["."]*cols]*rows
    for i, _ in enumerate(lines):
        for j, _ in enumerate(lines[i]):
            if (i, j) not in d:
                print(lines[i][j], end=" ")
            else:
                print(d[(i, j)], end=" ")
        print("\n")


main()
