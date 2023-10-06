L = []
# n = int(input("Ënter number of elements:"))
# for i in range(n):
#     L.append(input("Ënter:"))
L = ['23','12','56','02','15']
# print(L)
for i in range(1,-1,-1):
    L.sort(key=lambda x: x[i])
print(L)
