import copy

def main():
    part_one("../textfile/day11final.txt")

def part_one(filname):

    with open(filname,encoding="utf8") as f:
        lines = f.read().splitlines()
        #print("rows:",len(lines))
        #print("cols:",len(lines[93]))
        #print_matrix(lines)
        oldLine,newLine =  get_new_state(lines)
        #print_matrix(newLine)

        while not two_matrix_equal(oldLine,newLine):
            oldLine,newLine =  get_new_state(newLine)
            #print("old matrix\n")
            # print_matrix(oldLine)
            # print("new matrix\n")
            # print_matrix(newLine)

        print("Day 11 part one:",countNumberOfOccupiedSeats(oldLine))


def print_matrix(lines):
    for i,line in enumerate(lines):
        print(i,":",line)

def get_new_state(lines):
    new_line = [ "" * len(lines[0]) ] * len(lines)

    #print(new_line)
    for i in range(len(lines)):
        #print(len(lines[i]))
        for j in range(len(lines[i])):
            if lines[i][j] == "L":
                if empty_all_arround(i,j,lines):
                    new_line[i] += "#"
                else:
                    new_line[i] += "L"
            if lines[i][j] == "#":
                if hasAtLeastFourNonEmptySeats(i,j,lines):
                    new_line[i] += "L"
                else:
                    new_line[i] += "#"
            if lines[i][j] == ".":
                new_line[i] += "."



    return lines,new_line

#def part_two():

def empty_all_arround(i,j,lines):
    xdir = [-1,0,1]
    ydir = [-1,0,1]

    for x in xdir:
        for y in ydir:
            if (not( x == 0 and y == 0)
                    and x+i > -1 and x+i < len(lines)
                    and y+j > -1  and y+j < len(lines[0])
                    and isValidPoint(x+i,y+j,len(lines), len(lines[0]))
                    and lines[x+i][y+j] =='#'):
                return False
    return True





def isValidPoint(x,y,xMax,yMax):
    #if x < 2:
        #print(x,y,xMax,yMax)

    return not( x < 0 or x >= xMax or y < 0 or y>= yMax)


def hasAtLeastFourNonEmptySeats(i,j,lines):
    xdir = [-1,0,1]
    ydir = [-1,0,1]
    cnt = 0
    for x in xdir:
        for y in ydir:
            if (not( x == 0 and y == 0)
                    and isValidPoint(x+i,y+j,len(lines), len(lines[0]))
                    and lines[x+i][y+j] =='#'):
                    cnt+=1
    return cnt >3

def two_matrix_equal(oldLine,newLine):
    for i,_ in enumerate(oldLine):
        for j,_ in enumerate(oldLine[0]):
            if oldLine[i][j] != newLine[i][j]:
                return False
    return True

def countNumberOfOccupiedSeats(lines):
    cnt = 0
    for i,_ in enumerate(lines):
        for j,_ in enumerate(lines[0]):
            if lines[i][j] =="#":
                cnt+=1
    return cnt

main()