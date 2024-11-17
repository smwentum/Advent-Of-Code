
def main():
    part_one("../textfile/day2final.txt")
    part_two("../textfile/day2final.txt")

def part_one(file_name:str):
    with open(file_name, encoding="utf-8") as f:
        cnt = 0
        for line in f.readlines():
            split = line.split(" ")
            low,high = [int(x) for x in  split[0].split("-")]
            count_of_letters = split[2].count(split[1][0])
            if count_of_letters >= low and count_of_letters <= high:
                cnt+=1
        print("Day two part one:",cnt)

def part_two(file_name:str):
    with open(file_name, encoding="utf-8") as f:
        cnt = 0
        for line in f.readlines():
            split = line.split(" ")
            low,high = [int(x) for x in  split[0].split("-")]
            c = split[1][0]

            if (split[2][low-1] == c and split[2][high-1] != c) or  (split[2][low-1] != c and split[2][high-1] == c):
                cnt+=1

        print("Day 2 part two:",cnt)


main()