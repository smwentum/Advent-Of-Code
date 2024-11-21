def main():

    partOne("../textfile/day6final.txt")
    part_two("../textfile/day6final.txt")


def partOne(fileName: str):
    with open(fileName,encoding="utf-8") as f:
        lines = f.readlines()
        cnt =0
        s = set()
        for line in lines:
            if line.isspace():
                cnt += len(s)
                #print(len(s))
                s = set()
            else:
                for l in line.strip():
                    #print(l)
                    s.add(l)
        #last one
        cnt += len(s)
        print("Day six part one:",cnt)



def part_two(fileName: str):
    current = 0
    with open(fileName,encoding="utf-8") as f:
        lines = f.readlines()
        cnt =0
        firstLine =True
        for line in lines:
            if line.isspace():
                cnt += int.bit_count(current)
                current = 0
                firstLine =True
            else:
               if current == 0 and firstLine:
                   current = GetIntFromString(line)
                   firstLine = False
               else:
                   current = current & GetIntFromString(line)

        cnt += int.bit_count(current)
        print("Day six part two:",cnt)


def GetIntFromString(line:str) -> int:
    i = 0
    for l in line:
        #print(l)
        exp = ord(l)- ord('a')+1
        #print(exp)
        i = i | int(2**exp)
    return i


main()