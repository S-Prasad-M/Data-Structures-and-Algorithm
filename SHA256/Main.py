#https://www.youtube.com/watch?v=MHf6KUsv3bA

get_bin = lambda x, n: format(x, 'b').zfill(n)
def Ch(x,y,z):
    a=(x&y)^(-x&z) 
    return a
def Maj(x,y,z):
    a=(x&y)^(x&z)^(y&z)
    return a
def f1(x):
    a=get_bin(x,32) 
    i=rr(a,2)
    j=rr(a,13)
    k=rr(a,22)
    i=int(1,2)
    j=int(1,2)
    k=int(k,2)
    return i^j^k
def f2(x):
    a=get_bin(x,32)
    i=rr(a,6)
    j=rr(a,11)
    k=rr(a,25)
    i=int(1,2)
    j=int(1,2)
    k=int(k,2)
    return i^j^k
def f3(x):
    a=get_bin(x,32)
    i=rr(a,7)
    j=rr(a,18)
    k=x>>3
    i=int(1,2)
    j=int(1,2)
    return i^j^k
def f4(x):
    a=get_bin(x,32) 
    i=rr(a,17) 
    j=rr(a,19) 
    k=x>>10
    i=int(1, 2) 
    j=int(1,2)
    return i^j^k
def rr (x,y):
    a= (x[-y:] + x[:-y]) 
    return a
mod=4294967296 #### 2^32
W=[]
s='Group 14'
print "\n"+s 
slen=len(s)
i=0
a= [ord(c) for c in s] ##### convert message to res i=0
k=[1116352408,3624381080, 3835390401,2554220882,6663
h1=1779033703
h2=3144134277
h3=1013904242
h4-2773480762
h5-1359893119
h6=2600822924
h7=528734635
h8=1541459225
#### FILL UPTO 512 BITS IN a
a.append(128) # 10000000
n=len(s)
if(n %448!=0):
    for i in range(n,55):
        a.append(0)

