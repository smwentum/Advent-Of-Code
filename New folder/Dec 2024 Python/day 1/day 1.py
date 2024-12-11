def main():
    fileName="../textfiles/day1.txt"
    part_one(fileName)

def part_one(fileName):
    with open(fileName,encoding="utf8") as f:
        lines = f.readlines()

main()