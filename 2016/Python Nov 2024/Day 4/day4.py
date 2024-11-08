
from functools import total_ordering
from heapq import heappop, heappush

@total_ordering
class letterCode:
    c = '*'
    count = 0

    def __init__(self,c,cnt) -> None:
        self.c =c
        self.count = cnt
    
    def __lt__(self,other):
        if self.count < other.count:
            return True
        elif self.count > other.count:
            return False
        else:
            return self.c < other.c
    def __eq__(self, value: object) -> bool:
        return self.c == value.c and self.count == value.count
        


def main():
    partOne("../testfiles/day4final.txt")

def partOne(fileName):
    s =0 
    with open(fileName) as file: 
        for code in file.readlines():
          s +=  getSectorCodeIsValid(code)
    print("Day 4 part one: ", s)

def getSectorCodeIsValid(encrpted):
    p = encrpted.split("-")
    cnt = [0]*26
    h = []
    roomCode =0
    hashCode = ''
    for p1 in p: 
        if  str.isalpha(p1[0]):
            for c in p1:
                #print(ord(c)-ord('a'))
                cnt[ord(c)-ord('a')]+=1
        else:
            roomCode = int(p1.split("[")[0])
            hashCode = p1.split("[")[1].split("]")[0]
            # hashCode = hashCode[:len(hashCode)-2]
            print(hashCode)
    for i in range(len(cnt)): 
        heappush(h,letterCode(chr(ord('a') +i),cnt[i]*-1 ))
  
    myCode = ''
    for i in range(5):
        myCode+= heappop(h).c
    if myCode == hashCode:
        return roomCode
    return 0
    
     


main()