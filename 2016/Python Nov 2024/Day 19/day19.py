
def partOne(n):

    elfs = [1] *n
    #print(elfs)
    while n not in elfs:
        for i in range(n):
            if elfs[i] == n:
                print("part one answer:",i+1)
                break
            if elfs[i] > 0:
                for j in range(1,n):
                    if elfs[(i+j) % n] > 0:
                        elfs[i] += elfs[(i+j) %n]
                        elfs[(i+j) %n] = 0
                        break
    for i,ele in enumerate(elfs):
        if ele == n:
            print(i+1)




partOne(3004953)