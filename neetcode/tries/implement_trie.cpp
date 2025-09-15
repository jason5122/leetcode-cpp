/*
USED HINT
n == word.length()
runtime: O(n)
space: O(n)
*/
struct Node {
    array<Node*, 26> child{};
    bool is_end = false;
};

class Trie {
public:
    Trie() : root(new Node()) {}

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->child[i]) curr->child[i] = new Node();
            curr = curr->child[i];
        }
        curr->is_end = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->child[i]) return false;
            curr = curr->child[i];
        }
        return curr->is_end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!curr->child[i]) return false;
            curr = curr->child[i];
        }
        return true;
    }

private:
    Node* root;
};
