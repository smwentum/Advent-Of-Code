
def main():

    partOne("../textfile/day5final.txt")
    partTwo("../textfile/day5final.txt")

def partOne(fileName):

    with open(fileName, encoding="utf-8") as f:
        lines = f.readlines()
        m = 0
        for line in lines:
            #print(line)
            row = getRow(line)
            col = getCol(line[7:12])
            m = max(m, 8*row+col)
        print("Day 5 part One:",m)

def partTwo(fileName):
    set1 = set()
    for i in range(125*8):
        set1.add(i)
    with open(fileName, encoding="utf-8") as f:
        lines = f.readlines()
        m = 0
        for line in lines:
            #print(line)
            row = getRow(line)
            col = getCol(line[7:12])
            m = max(m, 8*row+col)
            #print(m)
            if 8*row+col in set1:
                set1.remove(8*row+col)
        for s1 in set1:
            if s1 >100 and s1 < 990:
                print("Day 5 Part Two:",s1)

def getSeatId(line):
    row = getRow(line[0:8])
    print(ResourceWarning)

def getRow(line) -> int:
    s = "";
    for l in line:
        if l == 'B':
            s+= '1'
        elif l == 'F':
            s += '0'
    return int(s,base=2)


def getCol(line) -> int:
    s = "";
    #print(line)
    for l in line:
        if l == 'R':
            s+= '1'
        elif l == 'L':
            s += '0'
    return int(s,base=2)


main()