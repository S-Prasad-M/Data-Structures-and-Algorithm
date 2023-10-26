import hashlib

# Function to compute the SHA-256 hash of a string
def computeSHA256Hash(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

# Function to build a Merkle Tree from a list of data items and print the full tree
def buildAndPrintMerkleTree(data):
    if not data:
        return None

    currentLayer = data
    fullTree = [currentLayer]  # To store all levels of the tree

    while len(currentLayer) > 1:
        newLayer = []

        for i in range(0, len(currentLayer), 2):
            combinedHash = currentLayer[i]
            if i + 1 < len(currentLayer):
                combinedHash += currentLayer[i + 1]

            newLayer.append(computeSHA256Hash(combinedHash))

        currentLayer = newLayer
        fullTree.append(currentLayer)

    return fullTree

# Function to print the Merkle Tree
def printMerkleTree(tree):
    for level, hashes in enumerate(tree):
        print(f"Level {level}:")
        for i, hash in enumerate(hashes):
            print(f"    Node {i}: {hash}")
        print()

# Example usage:
data = ["ABCD", "EFGH", "IJKL", "MNOP"]

fullTree = buildAndPrintMerkleTree(data)
print("Merkle Root:", fullTree[-1][0])  # Merkle Root is the last element

# Print the full tree
print("\nFull Merkle Tree:")
printMerkleTree(fullTree)


# import hashlib
# def build_merkle_tree(leaves):
#     if len(leaves) == 0:
#         return None
#     if len(leaves) == 1:
#         return leaves[0]
#     new_leaves = []
#     for i in range(0, len(leaves), 2):
#         data = leaves[i]
#         if i + 1 < len(leaves):
#             data += leaves[i + 1]
#         new_leaves.append(hash_data(data))
#     return build_merkle_tree(new_leaves)

# def hash_data(data):
#     return hashlib.sha256(data.encode()).hexdigest()

# if _name_ == "_main_":
#     data = ["A", "B", "C", "D"]
#     merkle_root = build_merkle_tree(data)
#     print("Merkle Root:", merkle_root)
