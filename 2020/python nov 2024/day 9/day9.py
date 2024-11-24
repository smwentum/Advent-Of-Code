import heapq

def main():
    part_one("../textfile/day9final.txt")
    part_two("../textfile/day9final.txt")

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
            return(lines[index])

        #print(currentList)


def part_two(fileName):

    with open(fileName,encoding="utf-8") as f:
        lines = list(map(int, f.read().splitlines()))
        part_one_answer = int(part_one(fileName))
        #i am going to do a sliding window
        s= 0
        l = 0
        r = 0
        while s != part_one_answer:
            #print("sumIWant,s:",part_one_answer,s)
            if s < part_one_answer:
                s += lines[r]
                r+=1

            elif s > part_one_answer:
                s -= lines[l]
                l += 1

        mx = -1
        mn = 10E40
        for i in range(l,r+1):
            if lines[i] > mx:
                mx = lines[i]
            if lines[i] < mn:
                mn = lines[i]

        print("day 9 part two answer",mx+mn)




main()