import heapq

def main():
    part_one("../textfile/day9final.txt")

def part_one(fileName):

    with open(fileName,encoding="utf-8") as f:
        lines = f.read().splitlines()

        preamble = 25

        currentList = []
        heap = []
        index = preamble
        for  x in range(preamble):
            #print(lines[x])

            currentList.append(int(lines[x]))
            heapq.heappush(heap,(x,int(lines[x])) )
        #print(heap)



        l = 0
        r = len(currentList)-1
        current_value = int(lines[index])
        #print("current value:",current_value)
        currentList.sort()
        while l < r:
            if currentList[l] + currentList[r] < current_value:
                l+=1
            elif currentList[l] + currentList[r] > current_value:
                r-=1
            else:
                #remove the list
                _,element_to_remmove = heapq.heappop(heap)
                #print("element to remove:",element_to_remmove)
                currentList.remove(element_to_remmove)
                heapq.heappush(heap,(index,current_value) )
                currentList.append(current_value)
                l = 0
                r = len(currentList)-1
                currentList.sort()
                #print(currentList)
                index+=1
                current_value = int(lines[index])
        if l >= r:
            print("Day nine part one:",(lines[index]))

        #print(currentList)




main()