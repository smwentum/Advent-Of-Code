def main():
    fileName = "../textfiles/day4final.txt"
    part_one(fileName)
    fileName = "../textfiles/day4final.txt"
    part_two(fileName)


def part_one(fileName):
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        cnt = 0
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[i]):
                if lines[i][j] == 'X':
                    cnt += getAllXMAS(lines, i, j)
        print("Day Four part 1:", cnt)


def part_two(fileName):
    with open(fileName, encoding="utf8") as f:
        lines = f.read().splitlines()
        cnt = 0
        for i, _ in enumerate(lines):
            for j, _ in enumerate(lines[i]):
                if lines[i][j] == 'A':
                    cnt += getAllXMASPT2A(lines, i, j)
        print("Day Four part 2:", cnt)


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


def getAllXMASPT2(lines, i, j):
    cnt = 0
    jmp = 4
    if (down_diag_right(lines, i-1, j-1) == 1 and down_diag_left(lines, i-1, j-1+jmp) == 1):
        cnt += 1

    if (down_diag_right(lines, i-1, j-1) == 1 and up_diag_right(lines, i-1+jmp, j-1) == 1):
        cnt += 1

    if (up_diag_right(lines, i+1, j-1) == 1 and down_diag_right(lines, i+1-jmp, j-1) == 1):
        cnt += 1

    if (up_diag_right(lines, i+1, j-1) == 1 and up_diag_right(lines, i+1, j-1+jmp) == 1):
        cnt += 1

    # cnt += up_diag_right(lines, i, j)
    # cnt += up_diag_left(lines, i, j)

    # cnt += down_diag_right(lines, i, j)
    # cnt += down_diag_left(lines, i, j)

    return cnt

def getAllXMASPT2A(lines, i, j):

    s = []
    if i >0 and i < len(lines) -1   and j > 0 and j < len(lines[i])  -1:
        if lines[i-1][j-1] == lines[i+1][j+1]:
            return 0
        s.append(lines[i-1][j-1])
        s.append(lines[i+1][j+1])
        s.append(lines[i+1][j-1])
        s.append(lines[i-1][j+1])
        s.sort()
        #print(s)
        if s[0] == "M" and s[1] == "M" and s[2] == "S" and s[3] == "S":
            return 1
    return 0



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
    if i < 3 or (i < len(lines) and len(lines[i])-j <= 3):
        return 0
    if lines[i-1][j+1] == 'M' and lines[i-2][j+2] == 'A' and lines[i-3][j+3] == 'S':
        return 1
    return 0


main()


# 2110 too high
