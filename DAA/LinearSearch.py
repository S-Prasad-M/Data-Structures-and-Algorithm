A = [4,23,1,12,8,2,12]
key = int(input("Enter element to search:"))
for i in range(len(A)):
    if A[i] == key:
        print(key," is found at index ", i)