def main():
    fileName = "../textfiles/day4final.txt"
    part_one(fileName)


def part_one(fileName):
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        cnt = 0
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[i]):
                if lines[i][j] == 'X':
                    cnt += getAllXMAS(lines, i, j)
        print("Day Four part 1:", cnt)


def getAllXMAS(lines, i, j):
    cnt = 0

    cnt += up(lines, i, j)
    cnt += down(lines, i, j)
    cnt += left(lines, i, j)
    cnt += right(lines, i, j)

    cnt += up_diag_right(lines, i, j)
    cnt += up_diag_left(lines, i, j)

    cnt += down_diag_right(lines, i, j)
    cnt += down_diag_left(lines, i, j)

    return cnt


def up(lines, i, j):
    if i < 3:
        return 0
    if lines[i-1][j] == 'M' and lines[i-2][j] == 'A' and lines[i-3][j] == 'S':
        return 1
    return 0


def left(lines, i, j):
    if j < 3:
        return 0
    if lines[i][j-1] == 'M' and lines[i][j-2] == 'A' and lines[i][j-3] == 'S':
        return 1
    return 0


def right(lines, i, j):
    if len(lines[i])-j <= 3:
        return 0
    if lines[i][j+1] == 'M' and lines[i][j+2] == 'A' and lines[i][j+3] == 'S':
        return 1
    return 0


def down(lines, i, j):
    if len(lines)-i <= 3:
        return 0
    if lines[i+1][j] == 'M' and lines[i+2][j] == 'A' and lines[i+3][j] == 'S':
        return 1
    return 0


def down_diag_left(lines, i, j):

    if len(lines)-i <= 3 or j < 3:
        return 0
    # print(i, j)
    if lines[i+1][j-1] == 'M' and lines[i+2][j-2] == 'A' and lines[i+3][j-3] == 'S':
        return 1

    # print(i, j)
    return 0


def down_diag_right(lines, i, j):
    if len(lines)-i <= 3 or len(lines[i])-j <= 3:
        return 0
    if lines[i+1][j+1] == 'M' and lines[i+2][j+2] == 'A' and lines[i+3][j+3] == 'S':
        return 1
    return 0


def up_diag_left(lines, i, j):
    if i < 3 or j < 3:
        return 0
    if lines[i-1][j-1] == 'M' and lines[i-2][j-2] == 'A' and lines[i-3][j-3] == 'S':
        return 1
    return 0


def up_diag_right(lines, i, j):
    if i < 3 or len(lines[i])-j <= 3:
        return 0
    if lines[i-1][j+1] == 'M' and lines[i-2][j+2] == 'A' and lines[i-3][j+3] == 'S':
        return 1
    return 0


main()
