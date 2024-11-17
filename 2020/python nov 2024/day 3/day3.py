def main():
    part_one("../textfile/day3final.txt")
    part_two("../textfile/day3final.txt")

def part_one(file_name:str):
    lines = []
    with open(file_name,encoding="utf-8") as f:
        for line in f.readlines():
            lines.append(line.strip())

    print("Day 3 part One:",getCount(lines,1,3))

def part_two(file_name:str):
    lines = []
    with open(file_name,encoding="utf-8") as f:
        for line in f.readlines():
            lines.append(line.strip())

    cnt = 1

    # Right 1, down 1.
    cnt *= getCount(lines,1,1)
    # Right 3, down 1. (This is the slope you already checked.)
    cnt *= getCount(lines,1,3)
    # Right 5, down 1.
    cnt *= getCount(lines,1,5)
    # Right 7, down 1.
    cnt *= getCount(lines,1,7)
    # Right 1, down 2.
    cnt *= getCount(lines,2,1)


    print("Day 3 part two:",cnt)

def getCount(lines, x_jump, y_jump) -> int:
    row = 0
    col = 0
    cnt = 0
    while row < len(lines):
        if lines[row][col] == '#':
            cnt += 1
        row+= x_jump
        col = (col+ y_jump) % len(lines[0])
    return cnt

main()