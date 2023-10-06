L = []
# n = int(input("Ënter number of elements:"))
# for i in range(n):
#     L.append(input("Ënter:"))
L = ['323','512','156','102','115']
# print(L)
for i in range(2,-1,-1):
    L.sort(key=lambda x: x[i])
print(L)
