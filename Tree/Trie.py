class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def delete(self, word):
        def _delete_recursive(node, word, index):
            if index == len(word):
                if not node.is_end_of_word:
                    return False
                node.is_end_of_word = False
                return len(node.children) == 0
            char = word[index]
            if char not in node.children:
                return False
            should_delete = _delete_recursive(node.children[char], word, index + 1)
            if should_delete:
                del node.children[char]
                return len(node.children) == 0
            return False

        _delete_recursive(self.root, word, 0)

    def view(self, node=None, prefix=""):
        if node is None:
            node = self.root
        for char, child in node.children.items():
            print(prefix + char)
            if child.is_end_of_word:
                print(" (end)")
            self.view(child, prefix + "  ")

# User menu
trie = Trie()

while True:
    print("\nTrie Menu:")
    print("1. Insert word")
    print("2. Delete word")
    print("3. Search word")
    print("4. View Trie")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        word = input("Enter the word to insert: ")
        trie.insert(word)
        print(f"'{word}' inserted into the trie.")

    elif choice == "2":
        word = input("Enter the word to delete: ")
        if trie.delete(word):
            print(f"'{word}' deleted from the trie.")
        else:
            print(f"'{word}' not found in the trie.")

    elif choice == "3":
        word = input("Enter the word to search: ")
        if trie.search(word):
            print(f"'{word}' found in the trie.")
        else:
            print(f"'{word}' not found in the trie.")

    elif choice == "4":
        print("Trie structure:")
        trie.view()

    elif choice == "5":
        break

    else:
        print("Invalid choice. Please enter a valid option.")
