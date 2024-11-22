def main():
    part_one("../textfile/day7final.txt")
    part_two("../textfile/day7final.txt")

def part_one(fileName: str):
    d = dict()
    with open(fileName,encoding="utf-8") as f:
        lines = f.readlines()
        for line in lines:
            bag = line.split('bags')[0].strip()
            cBags =  line.split('contain')[1].strip().split(',')
            #print(cBags)
            d[bag] = []
            for cbag in cBags:
                cbag = cbag.strip()
                if cbag != "no other bags.":
                    d[bag].append(cbag.split(' ')[1]+" "+cbag.split(' ')[2])
                #print(cbag)
        #print(d)
        cnt = 0

        for bag in d.keys():
            #print("in for loop looking at bag",bag)
            visted = []
            que = []
            que.append(bag)
            while len(que) > 0:
                #print("in while loop",que)

                cur = que.pop()
                if cur not in visted:

                    if cur == "shiny gold" and cur != bag:
                        cnt+= 1

                        break
                    else:
                        if cur not in visted:
                            que.extend(d[cur])
                    visted.append(cur)
        print("Part one day 7:",cnt)


counts = dict()


def part_two(fileName: str):
    d = dict()
    with open(fileName,encoding="utf-8") as f:
        lines = f.readlines()
        for line in lines:
            bag = line.split('bags')[0].strip()
            cBags =  line.split('contain')[1].strip().split(',')
            #print(cBags)
            d[bag] = []
            counts[bag] = -1
            for cbag in cBags:
                cbag = cbag.strip()
                if cbag != "no other bags.":
                    d[bag].append((cbag.split(' ')[1]+" "+cbag.split(' ')[2], int(cbag.split(' ')[0])))
                else:
                    counts[bag] = 1
                #print(cbag)
        #print(d)
        cnt = getCount(d,"shiny gold")-1
        # for bag in d.keys():
        #     #print("in for loop looking at bag",bag)
        #     visted = []
        #     que = []
        #     que.append(bag)
        #     while len(que) > 0:
        #         #print("in while loop",que)

        #         cur = que.pop()
        #         if cur not in visted:

        #             if cur == "shiny gold" and cur != bag:
        #                 cnt+= 1

        #                 break
        #             else:
        #                 if cur not in visted:
        #                     que.extend(d[cur])
        #             visted.append(cur)
        print("Part two day 7:",cnt)

def getCount(d,bag):
    if counts[bag] > -1:
        return counts[bag]
    s = 1
    for t in d[bag]:
        #print(t[1])
        s+= t[1]*getCount(d,t[0])

    counts[bag] =s
    print(bag,s)
    return s

main()