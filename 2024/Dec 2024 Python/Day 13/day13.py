def main():
    file_name = "../textfiles/day13final.txt"
    part_one(file_name)


def part_one(file_name):

    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        s = 0
        for i in range(0, len(lines)-4, 4):
            # first two lines get the two values
            ax = int(lines[i].split(":")[1].strip().split(",")[
                0].strip().split("+")[1])

            ay = int(lines[i].split(":")[1].strip().split(",")[
                1].strip().split("+")[1])

            bx = int(lines[i +
                           1].split(":")[1].strip().split(",")[0].strip().split("+")[1])

            by = int(lines[i +
                           1].split(":")[1].strip().split(",")[1].strip().split("+")[1])

            px = int(lines[i +
                           2].split(":")[1].strip().split(",")[0].strip().split("=")[1])

            py = int(lines[i +
                           2].split(":")[1].strip().split(",")[1].strip().split("=")[1])
            s += fewestTokens(ax, ay, bx, by, px, py)
        print("Day 13 part 1", s)


def fewestTokens(ax, ay, bx, by, px, py):
    lst = []
    for i in range(101):
        remaining_x = px-ax*i
        remaining_y = py-ay*i
        if remaining_x < 0 or remaining_y < 0:
            break
        if remaining_x % bx != 0 or remaining_y % by != 0:
            continue
        if int(remaining_x/bx) == int(remaining_y/by) and int(remaining_y/by) <= 100:
            lst.append((i, int(remaining_x/bx)))
    mn = 101*4+1

    for z in lst:
        mn = min(mn, z[0]*3+z[1]*1)
    if mn < 101*4+1:
        return mn
    return 0


main()
