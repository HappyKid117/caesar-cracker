def check(a):
    if(a=='A' or a=='E' or a=='I' or a=='O' or a=='U' or a=='Y'):
        return 1
    else:
        return 0

def weigh(s):
    w = 0
    n = len(s)
    for i in range(n):
        if(s[i]=='Y'):
            w+=1
        if(s[i]=='Z' or s[i]=='V'):
            w+=2
        if(i<n-1 and s[i+1]!=' ' and s[i]=='Q' and s[i+1]!='U'):
            w=1000
        elif(i<n-1 and s[i+1]!=' ' and s[i]=='Q' and s[i+1]=='U'):
            w=-100
        
        if(i<n-1 and s[i+1]!=' ' and s[i]=='X' and check(s[i+1])==0 ):
            w=1000
        
        if(i<n-1 and (s[i]=='O' and s[i+1] == 'O')):
            w-=5
        
        if(i<n-1 and (s[i]=='E' and s[i+1]=='E')):
            w-=5
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='H')):
            w-=5
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='C')):
            w-=10
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='S')):
            w-=10
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='T')):
            w-=5
        
        if(i<n-1 and (s[i]=='I' and s[i+1]=='E')):
            w-=5
        
        if(i<n-1 and (s[i]=='T' and s[i+1]=='H')):
            w-=5
        
        if(i<n-1 and (s[i]=='O' and s[i+1]=='U')):
            w-=5
        
        if(i<n-1 and (s[i]=='I' and s[i+1]=='S')):
            w-=50
        
        if(i<n-2 and (s[i]=='I' and s[i+1]=='O' and s[i+2]=='N')):
            w-=100
        
        if(i<n-2 and (s[i]=='I' and s[i+1]=='N' and s[i+2]=='G')):
            w-=100
        
        if(i<n-2 and (s[i]=='A' and s[i+1]=='N' and s[i+2]=='D')):
            w-=100
    
    return w

def sencheck(s):
    maxdevoid=0 
    devoid=0
    ok=0
    n = len(s)
    for i in range(n):
        if(s[i] == ' '):
            if(ok==0):
                maxdevoid = 1000
                break
            else:
                if(devoid>maxdevoid):
                    maxdevoid = devoid
            ok = 0
            devoid = 0
            continue
        if(check(s[i])):
            if(devoid>maxdevoid):
                maxdevoid=devoid
            ok = 1
            devoid = 0
        else:
            devoid+=1
    
    if ok==0:
        maxdevoid = 1000
    if devoid>=maxdevoid:
        maxdevoid = devoid
    return maxdevoid

def incr(s):
    n = len(s)
    a = ''
    for i in range(n):
        if s[i] == ' ':
            a+=' '
            continue
        if s[i]=='Z':
            a+='A'
        else:
            a+=chr(ord(s[i])+1)
    return a

ciphertxt = str(input())
Devoid = [0]*26
Weights = [0]*26
n = len(ciphertxt)

for i in range(26):
    ciphertxt = incr(ciphertxt)
    Devoid[i], Weights[i] = sencheck(ciphertxt), weigh(ciphertxt)

mini = 99999
for i in range(26):
    if Devoid[i]<mini:
        mini = Devoid[i]
        index = i
    if Devoid[i]<=mini+1:
        if Weights[i]<Weights[index]:
            index = i

print("A few possible decryptions are:")
print()

for i in range(26):
    ciphertxt = incr(ciphertxt)
    if Devoid[i]<=mini+1 and Weights[i]<n*5:
        print(ciphertxt)

print()
print("A possible decryption is:")
print()
for i in range(index+1):
    ciphertxt = incr(ciphertxt)
print(ciphertxt)