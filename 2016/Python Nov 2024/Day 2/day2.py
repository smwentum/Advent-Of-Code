

def main():
    dayTwoPartOne("../TextFiles/test1.txt")
    dayTwoPartTwo("../TextFiles/test1.txt")

def dayTwoPartOne(fileName):

    mat = [[1,2,3],[4,5,6], [7,8,9]]
    x = 1
    y = 1
    ans = ""

    #read in line by line
    with open(fileName,"r") as f:
        for s in f.readlines():
            (x,y) = getNewCode(s,x,y)
            ans = ans+str(mat[x][y])
            #print((x,y))
    print(ans)

def getNewCode(s,x,y):
    #print(s)
    for c in s:
        match c:
            case 'L':
                if y > 0:
                    y -=1
            case 'R':
                if y < 2:
                    y += 1
            case 'U':
                if x > 0:
                    x -= 1
            case 'D':
                if x < 2:
                    x += 1
        #print(c+str((x,y)))
    return (x,y)


def dayTwoPartTwo(fileName):

    mat = [['*','*','1','*','*']
          ,['*','2','3','4','*']
          ,['5','6','7','8','9']
          ,['*','A','B','C','*']
          ,['*','*','D','*','*'],]
    x = 2
    y = 0
    ans = ""

    #read in line by line
    with open(fileName,"r") as f:
        for s in f.readlines():
            (x,y) = getNewCodePt2(s,x,y,mat)
            ans = ans+str(mat[x][y])
            #print((x,y))
    print(ans)


def getNewCodePt2(s,x,y,mat):
    #print(s)
    for c in s:
        match c:
            case 'L':
                if y > 0 and mat[x][y-1] != '*' :
                    y -=1
            case 'R':
                if y < 4 and mat[x][y+1] != '*':
                    y += 1
            case 'U':
                if x > 0 and mat[x-1][y] != '*':
                    x -= 1
            case 'D':
                if x < 4 and mat[x+1][y] != '*' :
                    x += 1
        #print(c+str((x,y)))
    return (x,y)



main()
