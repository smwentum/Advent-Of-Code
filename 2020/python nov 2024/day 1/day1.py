
def main():

    day1Part1("../textfile/day1final.txt")
    day1Part2("../textfile/day1test.txt")

def day1Part1(fileName:str):
   set1 = set()
   with open(fileName) as f:
       for s in f.readlines():
           n = int(s)
           if 2020-n in set1:
               print("Day One Part One:",(2020-n)*n)
               break
           else:
                set1.add(n)

def day1Part2(fileName:str):
   lst = []
   with open(fileName) as f:
       for s in f.readlines():
           n = int(s)
           lst.append(n)

       #print("length of list"+str(len(lst)))

       for i,_ in enumerate(lst):
           for j1,j in enumerate(lst,i+1):
                for _,k in enumerate(lst,j1+1 ):

                    if lst[i]+j+k == 2020:
                        print("Day One Part Two:",lst[i]*j*k)
                        return


main()