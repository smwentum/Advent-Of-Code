import hashlib


def main():
   
    with open("./TestFiles/day5.txt") as f:
        key = f.readline()
    print(key)
    partOne(key)
    partTwo(key)

def partOne(baseString): 
    s = 't'
    i = 1
    ans = ''
    while len(ans) < 8 :
        s =  (hashlib.md5((baseString+str(i)).encode('utf-8')) ).hexdigest()
        if s.startswith('00000'):
            ans+=s[5]
        i+=1
        
    print(ans)

def partTwo(baseString): 
    s = ''
    i = 1
    ans = ['*'] *8
    while '*' in ans :
        s =  (hashlib.md5((baseString+str(i)).encode('utf-8')) ).hexdigest()
        if s.startswith('00000'):
            if str.isdigit( s[5]) and int(s[5]) < 8 and ans[int(s[5])] == '*'  :
                #print(s)
                ans[int(s[5])] =s[6]
                #print(ans)
        i+=1
        
    print(''.join(ans))
    

main()