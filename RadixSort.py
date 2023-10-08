#  Using String testing sample. Useless code
# L = []
# # n = int(input("Ënter number of elements:"))
# # for i in range(n):
# #     L.append(input("Ënter:"))
# L = ['323','512','156','102','115']
# # print(L)
# for i in range(2,-1,-1):
#     L.sort(key=lambda x: x[i])
# print(L)

l=eval(input("enter array in format [123,1323,134,52] : "))  
d={0:[],1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[],9:[]}
digits=len(str(max(l)))
mod=10
for i in range(digits):
    new_l=[]
    for _ in l:
        nl=d[(_%mod)//(mod/10)]
        nl.append(_)  
    for _ in d.values():
        new_l+=_
        _.clear()
    l=new_l
    mod*=10
    print("round",i)
    print(l)
    

