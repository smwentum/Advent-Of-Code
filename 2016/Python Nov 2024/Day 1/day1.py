
class PostionDirection:
    x = 0 
    y = 0
    facing = 0 
st = set()
def main():
    #need to read from a file
   partOne("../TestFiles/day1final.txt")
   partTwo("../TestFiles/day1final.txt")

def partOne(fileName): 
    with open(fileName,"r") as f:
        s = f.read()
        directions = s.split(", ")
        pos = PostionDirection()
        #print(directions)
        
        for direction in directions: 
            pos = getNewLocation(direction,pos,False)
    print("Day one part one answer: "+ str(abs(pos.x) + abs(pos.y)))

def partTwo(fileName): 
    with open(fileName,"r") as f:
        s = f.read()
        directions = s.split(", ")
        pos = PostionDirection()
        #print(directions)
        #st = set()
        st.add((0,0))
        
        for direction in directions: 
            pos = getNewLocation(direction,pos,True)
      
        
   # print("Day one part two answer: "+ str(abs(pos.x) + abs(pos.y)))
   

def getNewLocation(direction, pos,isPart2):
    #print(direction)
    if direction[0] == 'R':
        pos.facing -= 1
    elif direction[0] == 'L':
        pos.facing += 1
    #print(direction[1:])
    numOfSteps = int(direction[1:])
    while pos.facing < 0:
        pos.facing += 4
    while numOfSteps > 0:
        match pos.facing % 4:
            case 0:
                pos.y += 1
            case 1:
                pos.x += 1
            case 2:
                pos.y -= 1
            case 3:
                pos.x -= 1
        numOfSteps -= 1
        if isPart2:
            if (pos.x,pos.y) not in st: 
                    st.add((pos.x,pos.y))
            else:
                    print("Day one part two answer: "+ str(abs(pos.x) + abs(pos.y)))
                    quit()
    return pos    
        

main()