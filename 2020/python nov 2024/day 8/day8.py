def main():
    part_one("../textfile/day8final.txt")
    part_two("../textfile/day8final.txt")


def part_one(textfiles):
    with open(textfiles,encoding="utf-8") as f:

        lines = f.read().splitlines()
        current_line = 0
        s = set()
        acc =0
        while True:
            if current_line not in s:
                #print(current_line)
                s.add(current_line)
                #print(lines[current_line])
                match lines[current_line].split(' ')[0]:
                    case "acc":
                        #print(lines[current_line])
                        #print(lines[current_line].split(" ")[1])
                        acc += int(lines[current_line].split(" ")[1])
                        current_line+= 1
                    case "jmp":
                        current_line += int(lines[current_line].split(" ")[1])
                    case "nop":
                        current_line += 1
            else:
                print("Day eight part one:",acc)
                #print(s)
                break


def part_two(textfiles):
    with open(textfiles,encoding="utf-8") as f:

        lines = f.read().splitlines()

        for i,line in enumerate(lines):

            if lines[i].split(' ')[0] == 'nop':
                oLine = line
                nline = "jmp" + " " + line.split(' ')[1]
                lines[i] = nline
                done,acc = canGetToend(lines)
                if done:
                    print("Day eight part two:",acc)
                    break

                lines[i] = oLine
            elif lines[i].split(' ')[0] == 'jmp':

                oLine = line
                nline = "nop" + " " + line.split(' ')[1]
                lines[i] = nline
                done,acc = canGetToend(lines)
                if done:
                    print("Day eight part two:",acc)
                    break

                lines[i] = oLine


def canGetToend(lines):
    current_line = 0
    s = set()
    acc =0
    while True:
        if current_line not in s and current_line < len(lines):
            #print(current_line)
            s.add(current_line)
            #print(lines[current_line])
            match lines[current_line].split(' ')[0]:
                case "acc":
                    acc += int(lines[current_line].split(" ")[1])
                    current_line+= 1
                case "jmp":
                    current_line += int(lines[current_line].split(" ")[1])
                case "nop":
                    current_line += 1
        elif current_line  in s:
            return (False,0)
        else:
            return (True,acc)




main()
