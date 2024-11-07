def main():
    fileName = "../TextFiles/day3.txt"
    partOne(fileName)

def partOne(fileName):
    count = 0
    with open(fileName,"r") as f:
        for s in f.readlines():
            #print(s)
            (a ,b ,c) = s.split()
            if isValidTriangle(int(a),int(b),int(c)):
               count+=1
               #print((a,b,c),"is  a valid triangle")
            #else:
            #    print((a,b,c),"is not a valid triangle")
    print("Day 3 part 1:",count)

def isValidTriangle(a,b,c):
    if  a + b <= c:
        return False
    elif b + c <= a:
        return False
    elif c + a <= b:
        return False
    return True

main()