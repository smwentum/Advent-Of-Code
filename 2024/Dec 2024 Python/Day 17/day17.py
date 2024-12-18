def main():
    file_name = "../textfiles/day17final.txt"
    part_one(file_name)
    file_name = "../textfiles/day17test6.txt"
    part_two(file_name)

def part_one(file_name):

    with open(file=file_name,encoding="utf8") as f:
        lines = f.read().splitlines()
        print(lines[0].split(":")[1].strip())
        a = int(lines[0].split(":")[1].strip())
        b = int(lines[1].split(":")[1].strip())
        c = int(lines[2].split(":")[1].strip())
        print(a,b,c)

        lst = [int (x) for x in  lines[4].split(":")[1].strip().split(",")]

        print(lst)

        out = []
        i = 0
        while i >=0 and i < len(lst) -1:
            a,b,c,i,out = doOperation(lst,a,b,c,i,out)
        print("a",a,"b",b,"c",c)
        #print(out)
        print("Part one")
        print(",".join([str(x) for x in out]))
        #7,5,0,3,7,0,0,7,2


def part_two(file_name):
    with open(file=file_name,encoding="utf8") as f:
        lines = f.read().splitlines()
        #print(lines[0].split(":")[1].strip())
        a = int(lines[0].split(":")[1].strip())
        b = int(lines[1].split(":")[1].strip())
        c = int(lines[2].split(":")[1].strip())
        #print(a,b,c)

        lst = [int (x) for x in  lines[4].split(":")[1].strip().split(",")]
        print("Part 2")
        #print(lst)

        out = []
        i = 0
        cnt = 117439-1
        a = cnt
        while out != lst:
            out = []
            while i >=0 and i < len(lst) - 1:
                a,b,c,i,out = doOperation2(lst,a,b,c,i,out)

            print(cnt,out)
            cnt += 1
            a = cnt
            i = 0



        print("a",a,"b",b,"c",c)
        #print(out)
        print(",".join([str(x) for x in out]))
        #7,5,0,3,7,0,0,7,2



# def part_two(file_name):
#     with open(file=file_name,encoding="utf8") as f:
#         lines = f.read().splitlines()
#         print(lines[0].split(":")[1].strip())
#         a = int(lines[0].split(":")[1].strip())
#         b = int(lines[1].split(":")[1].strip())
#         c = int(lines[2].split(":")[1].strip())
#         print(a,b,c)

#         lst = [int (x) for x in  lines[4].split(":")[1].strip().split(",")]

#         print(lst)

#         out = []
#         i = 0
#         while i >=0 and i < len(lst) -1:
#             a,b,c,i,out = doOperation(lst,a,b,c,i,out)
#         print("a",a,"b",b,"c",c)
#         print(out)
#         print(",".join([str(x) for x in out]))
#         #7,5,0,3,7,0,0,7,2

def doOperation(lst,a,b,c,i,out):
    opCode = lst[i]
    combo = lst[i+1]
    #print("i:",i)
    literal_opCode = getLiteralValue(opCode,a,b,c)
    literal_combo = getLiteralValue(combo,a,b,c)
    #print("op code:",opCode,"combo",combo )
    #print("litteral op code:",opCode," litteral combo",combo )

    match lst[i]:
        case 0:
           #print("case 0: ",literal_combo)
           a=  int(a/(2**literal_combo ))
           #print("case 0 a is now:",a)
        case 1:
           #print(b)
           #print(literal_combo)
           #print(literal_opCode)

           b = b ^ combo
        case 2:
           b = literal_combo % 8
        case 3:
           #print("in case 3 a is:",a)
           #print("case 3: opcode",opCode)
           #print("case 3: literal_opcode",literal_opCode)
           if a != 0:
                i = combo-2
        case 4:
            b = b ^ c
            #i-=1
        case 5:
            #print("5:",literal_combo)

            out.append( literal_combo % 8)
            # if  len(out) > len(lst):
            #         return (a,b,c,i+2,out)
            # for i in range(len(out)):
            #     if out[i] != lst[i]:
            #         return (a,b,c,i+2,out)
            #print("printing: ",literal_combo%8)
        case 6:
            b=  int(a/(2**literal_combo ))
        case 7:
            c = int(a/(2**literal_combo ))
    return (a,b,c,i+2,out)

def doOperation2(lst,a,b,c,i,out):
    opCode = lst[i]
    combo = lst[i+1]
    #print("i:",i)
    literal_opCode = getLiteralValue(opCode,a,b,c)
    literal_combo = getLiteralValue(combo,a,b,c)
    #print("op code:",opCode,"combo",combo )
    #print("litteral op code:",opCode," litteral combo",combo )

    match lst[i]:
        case 0:
           #print("case 0: ",literal_combo)
           a=  int(a/(2**literal_combo ))
           #print("case 0 a is now:",a)
        case 1:
           #print(b)
           #print(literal_combo)
           #print(literal_opCode)

           b = b ^ combo
        case 2:
           b = literal_combo % 8
        case 3:
           #print("in case 3 a is:",a)
           #print("case 3: opcode",opCode)
           #print("case 3: literal_opcode",literal_opCode)
           if a != 0:
                i = combo-2
        case 4:
            b = b ^ c
            #i-=1
        case 5:
            #print("5:",literal_combo)

            out.append( literal_combo % 8)
            if  len(out) > len(lst):
                    return (a,b,c,i+2,out)
            if  len(out) <= len(lst):
                for i in range(len(out)):
                    if out[i] != lst[i]:
                        return (a,b,c,i+2,out)
            #print("printing: ",literal_combo%8)
        case 6:
            b=  int(a/(2**literal_combo ))
        case 7:
            c = int(a/(2**literal_combo ))
    return (a,b,c,i+2,out)


def getLiteralValue(x,a,b,c):
    if x < 4:
        return x
    if x == 4:
        return a
    if x == 5:
        return b
    if x == 6:
        return c
    return -1




main()