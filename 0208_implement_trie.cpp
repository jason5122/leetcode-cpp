#include <iostream>
#include <map>
using namespace std;

class Trie {
   private:
    map<char, Trie*> next = {};
    bool is_word = false;

   public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->is_word = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return node->is_word;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }
};

int main() {
    Trie trie = Trie();
    trie.insert("apple");
    bool result = trie.search("apple");  // true
    cout << result << '\n';
    result = trie.search("app");  // false
    cout << result << '\n';
    result = trie.startsWith("app");  // true
    cout << result << '\n';
    trie.insert("app");
    result = trie.search("app");  // true
    cout << result << '\n';
}
