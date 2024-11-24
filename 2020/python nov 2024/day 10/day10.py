import heapq

def main():
    part_one("../textfile/day10final.txt")

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



main()