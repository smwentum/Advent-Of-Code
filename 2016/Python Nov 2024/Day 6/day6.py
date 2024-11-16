from collections import Counter
def main():
    partOne("./testFiles/day6Final.txt")
    partTwo("./testFiles/day6Final.txt")

def partOne(fileNameAndPath): 

        with open(fileNameAndPath) as f:
            lines = f.read().splitlines()
        mat = [ ['*']*len(lines[0]) for _ in range(len(lines))]
        #print(mat)
        for i,line in enumerate(lines): 
            for j,c in enumerate(line):
                #print(i,j) 
                mat[i][j] = c
        #print(mat)
        #print()
        #print([row[0] for row in mat])
        ans = []
        for i in range(len(lines[0])):
            ans.append(Counter([row[i] for row in mat]).most_common()[0][0])
        print("answer to part one: "+ ''.join(ans))


def partTwo(fileNameAndPath): 

        with open(fileNameAndPath) as f:
            lines = f.read().splitlines()
        mat = [ ['*']*len(lines[0]) for _ in range(len(lines))]
        #print(mat)
        for i,line in enumerate(lines): 
            for j,c in enumerate(line):
                #print(i,j) 
                mat[i][j] = c
        #print(mat)
        #print()
        #print([row[0] for row in mat])
        ans = []
        for i in range(len(lines[0])):
            #print(Counter([row[i] for row in mat]).most_common()[:-1][0][0])
            ans.append(Counter([row[i] for row in mat]).most_common()[-1][0])
        print("answer to part two: "+''.join(ans))

main()