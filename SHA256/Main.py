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
    j=arr(a,18)
    k=x>>3
    i=int(1,2)
    j=int(1,2)
    return i^j^k
