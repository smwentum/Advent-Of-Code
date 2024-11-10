import hashlib


def main():
    partOne("abbhdwsy")

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
    

main()