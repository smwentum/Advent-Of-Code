import math


def main():
    file_name = "../textfiles/day13final.txt"
    part_one(file_name)
    file_name = "../textfiles/day13test.txt"
    part_two(file_name)


def part_one(file_name):

    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        s = 0
        for i in range(0, len(lines)-4, 4):
            # first two lines get the two values
            ax = int(lines[i].split(":")[1].strip().split(",")[
                0].strip().split("+")[1])

            ay = int(lines[i].split(":")[1].strip().split(",")[
                1].strip().split("+")[1])

            bx = int(lines[i +
                           1].split(":")[1].strip().split(",")[0].strip().split("+")[1])

            by = int(lines[i +
                           1].split(":")[1].strip().split(",")[1].strip().split("+")[1])

            px = int(lines[i +
                           2].split(":")[1].strip().split(",")[0].strip().split("=")[1])

            py = int(lines[i +
                           2].split(":")[1].strip().split(",")[1].strip().split("=")[1])
            s += fewestTokens(ax, ay, bx, by, px, py)
        print("Day 13 part 1", s)


def part_two(file_name):

    with open(file=file_name, encoding="utf8") as f:
        lines = f.read().splitlines()
        s = 0
        for i in range(0, len(lines)-4, 4):
            # first two lines get the two values
            ax = int(lines[i].split(":")[1].strip().split(",")[
                0].strip().split("+")[1])

            ay = int(lines[i].split(":")[1].strip().split(",")[
                1].strip().split("+")[1])

            bx = int(lines[i +
                           1].split(":")[1].strip().split(",")[0].strip().split("+")[1])

            by = int(lines[i +
                           1].split(":")[1].strip().split(",")[1].strip().split("+")[1])

            px = int(lines[i +
                           2].split(":")[1].strip().split(",")[0].strip().split("=")[1])

            py = int(lines[i +
                           2].split(":")[1].strip().split(",")[1].strip().split("=")[1])
            bigSum = 10000000000000
            s += fewestTokensPt2(ax, ay, bx, by, px+bigSum, py+bigSum)
        print("Day 13 part 2", s)
        # 74525886997073 too low


def fewestTokens(ax, ay, bx, by, px, py):
    lst = []
    for i in range(101):
        remaining_x = px-ax*i
        remaining_y = py-ay*i
        if remaining_x < 0 or remaining_y < 0:
            break
        if remaining_x % bx != 0 or remaining_y % by != 0:
            continue
        if int(remaining_x/bx) == int(remaining_y/by) and int(remaining_y/by) <= 100:
            lst.append((i, int(remaining_x/bx)))
    mn = 101*4+1

    for z in lst:
        mn = min(mn, z[0]*3+z[1]*1)
    if mn < 101*4+1:
        return mn
    return 0


def fewestTokensPt2(ax, ay, bx, by, px, py):
    lst = []
    A = ax+ay
    B = bx+by
    C = px+py
    
    # #print(G)
    # if C < G or C % G != 0:
    #     return 0
    # # print(int(C/G))

    # _, s, t = extendGcd(A, B)
    # s = s*int(C/G)
    # t = t*int(C/G)

    # low = int(math.ceil(-1*s/B))
    # high = int(math.floor(t/A))

    # print(low, high)
    # # for k in range(low, high+1):
    # lst.append((s+B*low, t-A*low))
    # lst.append((s+B*high, t-A*high))

    # mn = 2**63 - 1

    # for z in lst:
    #     mn = min(mn, z[0]*3+z[1]*1)
    # if mn < 2**63 - 1:
    #     return mn
    # return 0
    # print("s:", s, "t:", t)
    # print(s*A, t*B, C, s*A*int(C/G), t*B*int(C/G), (s*A+t*B)*int(C/G) == C)

    # # sol2 = (s*A*int(C/G) - 2*B/G, t*B*int(C/G) + 2*B/G)
    # # j = 1
    # # while sol2[0] > 0:
    # #     sol2 = (s*A*int(C/G) - j*B/G, t*B*int(C/G) + j*B/G)
    # #     j -= 1
    # # print(j)
    # # print((s*A*int(C/G) - j*B/G, t*B*int(C/G) + j*B/G))
    # s*A+t*B == G

    # _, s1, t1 = extendGcd(s, t)
    # print(s1, t1)
    # print(s*s1+t*t1)

    return 0


def extendGcd(a, b):
    if a == 0:
        return (b, 0, 1)

    gcd, x1, y1 = extendGcd(b % a, a)
    x = y1 - (b//a)*x1
    y = x1
    return gcd, x, y


# lst = []
# A = 94+34
# B = 22+67
# C = 8400+5400
# G = math.gcd(A, B)
# print("GCD:", G)

# print(int(C/G))

# _, s, t = extendGcd(A, B)
# s = s*int(C/G)
# t = t*int(C/G)

# low = int(math.floor(-1*s/B))
# high = int(math.ceil(t/A))

# print(low, high)

# print("s:", s, "t:", t)
# print("a:", A, "b:", B)
# print(s*A, t*B, C, (s*A+t*B) == C)

# j = 0
# while s-B/G*j > 0:0
#     if t/G*j+t >= 0:
#         print((s-B/G*j, t/G*j+t))

#     j += 1


# sol2 = (s*A*int(C/G) - 2*B/G, t*B*int(C/G) + 2*B/G)
# j = 1
# while sol2[0] > 0:
#     sol2 = (s*A*int(C/G) - j*B/G, t*B*int(C/G) + j*B/G)
#     j -= 1
# print(j)
# print((s*A*int(C/G) - j*B/G, t*B*int(C/G) + j*B/G))

main()
