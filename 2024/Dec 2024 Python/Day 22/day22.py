def main():
    file_name = "../textfiles/day22final.txt"
    part_one(file_name)


def part_one(file_name):
    with open(file=file_name, encoding="utf8") as f:
        secret_numbers = [int(x) for x in f.read().splitlines()]
        s = 0
        for secret_number in secret_numbers:
            x1 = secret_number
            for _ in range(2000):

                # print(x1)
                x1 = get_next_secret_number(x1)
            s += x1
           # print(secret_number, ":", x1)
        print("Day 22 part one:", s)


def get_next_secret_number(x):
    x64 = x*64
    x = mix_number(x, x64)
    x = prune(x)
    x32 = int(x / 32)
    x = mix_number(x, x32)
    x = prune(x)
    x2048 = x*2048
    x = mix_number(x, x2048)
    x = prune(x)
    return x


def mix_number(x, y):
    return x ^ y


def prune(x):
    return x % 16777216


main()
