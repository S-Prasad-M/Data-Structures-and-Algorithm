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
    i=int(i,2)
    j=int(j,2)
    k=int(k,2)
    return i^j^k
def f2(x):
    a=get_bin(x,32)
    i=rr(a,6)
    j=rr(a,11)
    k=rr(a,25)
    i=int(i,2)
    j=int(j,2)
    k=int(k,2)
    return i^j^k
def f3(x):
    a=get_bin(x,32)
    i=rr(a,7)
    j=rr(a,18)
    k=x>>3
    i=int(i,2)
    j=int(j,2)
    return i^j^k
def f4(x):
    a=get_bin(x,32) 
    i=rr(a,17) 
    j=rr(a,19) 
    k=x>>10
    i=int(i, 2) 
    j=int(j,2)
    return i^j^k
def rr (x,y):
    a= (x[-y:] + x[:-y]) 
    return a
mod=4294967296 #### 2^32
w=[]
s='SHREE PRASAD M'
print("\n"+s) 
slen=len(s)
i=0
a= [ord(c) for c in s] ##### convert message to res i=0
k = [
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
]
for i in range(64):
    k[i] = int(k[i])

h1=1779033703
h2=3144134277
h3=1013904242
h4=2773480762
h5=1359893119
h6=2600822924
h7=528734635
h8=1541459225
#### FILL UPTO 512 BITS IN a
a.append(128) # 10000000
n=len(s)
if(n %448!=0):
    for i in range(n,55):
        a.append(0)

#### Store length in last 64 bits
n = len(s)
slenbin = get_bin(n,64)
i = 0;j = 8
while j<=64:
    q = slenbin[i:j]
    a.append(int(q,2))
    i += 8; j += 8

i = 0; j = 0
n = len(a)

#### CREATE 32 BIT WORDS IN w
while i<n:
    temp = get_bin(a[i],8)+get_bin(a[i+1],8)+get_bin(a[i+2],8)+get_bin(a[i+3],8)
    w.append(int(temp,2))
    i += 4

for i in range(16,64):
    w.append((f4(w[i-2])+w[i-7]+f1(w[i-15])+w[i-16])%mod)


for i in range(64):
    temp1 =  (h8+f2(h5)+Ch(h5,h6,h7)+k[i]+w[i])%mod
    temp2 = (f1(h2)+Maj(h1,h2,h3))%mod
    t8 = h7
    t7 = h6
    t6 = h5
    t5 = (h4+temp1)%mod
    t4 = h3
    t3 = h2
    t2 = h1
    t1 = (temp1+temp2)%mod

    h1 = (t1+h1)%mod
    h2 = (t2+h2)%mod
    h3 = (t3+h3)%mod
    h4 = (t4+h4)%mod
    h5 = (t5+h5)%mod
    h6 = (t6+h6)%mod
    h7 = (t7+h7)%mod
    h8 = (t8+h8)%mod
print(hex(h1)[2:]+" "+hex(h2)[2:]+" "+hex(h3)[2:]+" "+hex(h4)[2:]+" "+hex(h4)[2:]+" "+hex(h5)[2:]+" "+hex(h6)[2:]+" "+hex(h7)[2:]+" "+hex(h8)[2:])
