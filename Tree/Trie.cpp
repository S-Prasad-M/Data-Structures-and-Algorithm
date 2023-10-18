#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <unordered_map>
#include <mutex>

class Trie {
public:
    Trie() {
        root = std::make_unique<Node>();
    }

    void insert(const std::string& word) {
        Node* current = root.get();
        for (char l : word) {
            if (current->child.find(l) == current->child.end()) {
                current->child[l] = std::make_unique<Node>();
            }
            current = current->child[l].get();
        }
        current->is_end = true;
    }

    bool search(const std::string& word) {
        Node* current = root.get();
        for (char l : word) {
            if (current->child.find(l) == current->child.end()) {
                return false;
            }
            current = current->child[l].get();
        }
        return current->is_end;
    }

    bool startsWith(const std::string& prefix) {
        Node* current = root.get();
        for (char l : prefix) {
            if (current->child.find(l) == current->child.end()) {
                return false;
            }
            current = current->child[l].get();
        }
        return true;
    }

private:
    struct Node {
        std::unordered_map<char, std::unique_ptr<Node>> child;
        bool is_end = false;
    };

    std::unique_ptr<Node> root;
};

void processFrame(const std::string& frame, Trie& trie, std::mutex& mtx) {
    for (size_t i = 0; i < frame.length(); ++i) {
        for (size_t j = i; j < frame.length(); j += frame.length()) {
            trie.insert(frame.substr(j, frame.length()));
        }
    }
}

int main() {
    Trie ob1;

    // Read data from the file
    std::ifstream data("Vibrio_cholerae.txt");
    if (!data) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::string a((std::istreambuf_iterator<char>(data)), std::istreambuf_iterator<char>());

    std::string s;
    std::cout << "Sequence: ";
    std::cin >> s;

    // Create and run threads for processing frames
    std::vector<std::thread> threads;
    const int numThreads = std::thread::hardware_concurrency();
    const size_t frameSize = s.length() / numThreads;
    std::mutex mtx;  // Mutex for protecting access to the Trie

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(processFrame, std::ref(s), std::ref(ob1), std::ref(mtx));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << (ob1.search(s) ? "Found" : "Not Found") << std::endl;

    return 0;
}
