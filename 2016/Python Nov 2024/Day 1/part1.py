
class PostionDirection:
    x = 0 
    y = 0
    facing = 0 

def main():
    #need to read from a file
    with open("../TestFiles/day1final.txt","r") as f:
        s = f.read()
        directions = s.split(", ")
        pos = PostionDirection()
        print(directions)
        
        for direction in directions: 
            pos = getNewLocation(direction,pos)
    print(abs(pos.x) + abs(pos.y))

def getNewLocation(direction, pos):
    print(direction)
    if direction[0] == 'R':
        pos.facing -= 1
    elif direction[0] == 'L':
        pos.facing += 1
    #print(direction[1:])
    numOfSteps = int(direction[1:])
    while pos.facing < 0:
        pos.facing += 4
    match pos.facing % 4:
        case 0:
            pos.y += numOfSteps
        case 1:
            pos.x += numOfSteps
        case 2:
            pos.y -= numOfSteps
        case 3:
            pos.x -= numOfSteps
    return pos


main()