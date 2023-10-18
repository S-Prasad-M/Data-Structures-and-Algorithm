class Trie(object):
   def __init__(self):
      self.child = {}
   def insert(self, word):
      current = self.child
      for l in word:
         if l not in current:
            current[l] = {}
         current = current[l]
      current['#']=1
   def search(self, word):
      current = self.child
      for l in word:
         if l not in current:
            return False
         current = current[l]
      return '#' in current
   def startsWith(self, prefix):
      current = self.child
      for l in prefix:
         if l not in current:
            return False
         current = current[l]
      return True
a = 'ACAATGAGGTCACTATGTT'
ob1 = Trie()
n = int(input("mer mer:"))
for i in range(n):
   for j in range(i,len(a),n):
      ob1.insert(a[j:j+n])

a = input("Sequence:")
print(ob1.search(a))

# print(ob1.search("app"))
# print(ob1.startsWith("app"))
