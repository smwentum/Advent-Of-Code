import heapq

def main():
    part_one("../textfile/day10final.txt")
    part_two("../textfile/day10final.txt")

def part_one(fileName):
    with open(fileName,encoding="utf-8") as f:
        heap = list(map(int, f.read().splitlines()))
        mx = max(heap)
        heapq.heapify(heap)
        heapq.heappush(heap,mx+3)
        current_wattage = 0
        #print(heap)
        diff1 = 0
        diff3 = 0
        # print(heapq.heappop(heap))
        while len(heap) > 0:
            currrent_adaptor  = heapq.heappop(heap)

            # if len(heap) == 1:
            #     currrent_adaptor +=3
            #print("wattage:",current_wattage,"adaptor:",currrent_adaptor)
            if  currrent_adaptor - current_wattage == 3:
                diff3+=1
                current_wattage = currrent_adaptor
            if currrent_adaptor - current_wattage == 1:
                diff1+=1
                current_wattage = currrent_adaptor
        #print("1-diff",diff1)
        #print("3-diff",diff3)
        print("Day 10 part one:",diff1*diff3 )

def part_two(fileName):


    with open(fileName,encoding="utf-8") as f:
        h = list(map(int, f.read().splitlines()))
        s.add(0)
        s.add(max(h)+3)
        for x in h:
            s.add(x)
        d[max(h)+3] =1

    #i am going to try memoization with recursion
    print("Day 10 part two", getValue(0))

def getValue(v):
    #print(v)
    if v in d:
        return d[v]
    s1 = 0
    if v in s:
        s1 = getValue(v+1)+ getValue(v+2) + getValue(v+3)

    d[v] = s1
    return s1

d = dict()
s = set()


main()