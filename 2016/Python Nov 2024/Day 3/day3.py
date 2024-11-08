def main():
    fileName = "../TextFiles/day3.txt"
    partOne(fileName)
    partTwo(fileName)



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


def partTwo(fileName):
    count = 0
    with open(fileName,"r") as f:
        l1 = []
        l2 = []
        l3 = []

        for s in f.readlines():
            #print(s)
            (a ,b ,c) = s.split()
            l1.append(int(a))
            l2.append(int(b))
            l3.append(int(c))
        #l1.sort()
        #l2.sort()
        #l3.sort()
       # print(l1)




        for i in range(0,len(l1),3):
            #print(i)
            #print(l1[i],l1[i+1],l1[i+2])
            if isValidTriangle(l1[i],l1[i+1],l1[i+2]):
                count+= 1
        for i in range(0,len(l2),3):
            #print(l1[i],l1[i+1],l1[i+2])
            if isValidTriangle(l2[i],l2[i+1],l2[i+2]):
                count+= 1

        for i in range(0,len(l3),3):
            #print(l1[i],l1[i+1],l1[i+2])
            if isValidTriangle(l3[i],l3[i+1],l3[i+2]):
                count+= 1


    print("Day 3 part 2:",count)


main()