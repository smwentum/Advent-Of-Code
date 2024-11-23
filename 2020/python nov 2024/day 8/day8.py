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
                print("Day eight part two:",acc)
                #print(s)
                break




main()
