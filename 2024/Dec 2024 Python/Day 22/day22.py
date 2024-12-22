def main():
    file_name = "../textfiles/day22final.txt"
    part_one(file_name)
    file_name = "../textfiles/day22final.txt"
    part_two(file_name)


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


def part_two(file_name):
    with open(file=file_name, encoding="utf8") as f:
        secret_numbers = [int(x) for x in f.read().splitlines()]
        s = 0
        s1 = set()
        l2 = []
        for secret_number in secret_numbers:
            x1 = secret_number
            lst = []
            lst.append(x1)
            for _ in range(2000):

                x1 = get_next_secret_number(x1)
                lst.append(x1)
            d1 = dict()
            get_diffs(d1, lst)
            for x, _ in d1.items():
                s1.add(x)
            l2.append(d1)
            # print(d1)

        mx = 0
        s2 = 0
        for s in s1:
            s2 = 0
            for d in l2:
                if s in d:
                    s2 += d[s]
            mx = max(mx, s2)
        print("Day 22 part two:", mx)


def get_diffs(d1, lst):
    lst1 = []
    for i in range(len(lst)-1):
        lst1.append((lst[i+1] % 10)-(lst[i] % 10))

    # print(lst1)
    for i in range(len(lst1)-4):
        current = (lst1[i], lst1[i+1], lst1[i+2], lst1[i+3])
        if current not in d1:
            d1[current] = lst[i+4] % 10


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
