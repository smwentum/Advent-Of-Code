def main():
    filename = "../textfiles/day9final.txt"
    part_one(filename)
    filename = "../textfiles/day9test.txt"
    part_two(filename)


def part_one(filename):

    with open(file=filename, encoding="utf8") as f:
        line = f.readline()
        # print(line)
        decompated = []
        index = 0

        for i,_ in enumerate(line):
            number_of_times = int(line[i])
            # print(number_of_times)
            if i%2 == 0:
                decompated+=[index]*number_of_times
                index += 1
            else:
                decompated+=[-1]*number_of_times

        #print(decompated)
        blanks = [i for i,x in enumerate(decompated) if x == -1]

        #print("blanks",blanks)
        for i in blanks:
            #remove the blanks at the end
            while decompated[-1] == -1:
                decompated.pop()
            if len(decompated) <= i:
                    break
            decompated[i]=decompated.pop()
        #print(decompated)
        print("Day 9 part One:", getCheckSum(decompated))
        # 6334393041104 -too low
        # 6334655984939

def part_two(filename):

    with open(file=filename, encoding="utf8") as f:
        line = f.readline()
        # print(line)
        decompated = []
        index = 0

        for i,_ in enumerate(line):
            number_of_times = int(line[i])
            # print(number_of_times)
            if i%2 == 0:
                decompated.append((index,number_of_times))
                index += 1
            else:
                decompated.append( (-1,number_of_times))

        blanks = [i for i,x in enumerate(decompated) if x[0] == -1]


        print("blanks",blanks)

        for i in blanks:
            #remove the blanks at the end
            #print("65:",decompated[-1][0])
            while decompated[-1][0] == -1:
                decompated.pop()
            if len(decompated) <= i:
                    break
            #print("70", decompated[:-1][1], decompated[i][1])
            if decompated[:-1][1][1] <= decompated[i][1]:

                a,b=decompated.pop()
                #print("73",a,b,decompated[i][1])
                decompated[i]=(a, b)
                if  decompated[i][1]-b > 0:
                    decompated.insert(i+1,(-1,decompated[i][1]-b))
                blanks = [i for i,x in enumerate(decompated) if x[0] == -1]

                continue
            print(decompated)

        print(decompated)

        # print("Day 9 part Two:", getCheckSum(decompated))
        # 6334393041104 -too low
        # 6334655984939

def getCheckSum(decompated):
    s = 0
    for i, val in enumerate(decompated):
        # print(val, i)
        if val != -1:
            s += i*val
    return s


main()
