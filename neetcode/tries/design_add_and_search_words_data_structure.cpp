/*
USED PARTIAL SOLUTION
*/
struct Node {
    array<Node*, 26> child{};
    bool is_end = false;
};

class WordDictionary {
public:
    WordDictionary() : root(new Node()) {}

    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->child[i]) curr->child[i] = new Node();
            curr = curr->child[i];
        }
        curr->is_end = true;
    }

    /*
    n == # of keys
    k == word.length()
    runtime: O(n*26^k)
    space: O(k)
    */
    bool search(string word) {
        return search_helper(word, root);
    }

private:
    bool search_helper(string word, Node* node) {
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (Node* child : node->child) {
                    if (child && search_helper(word.substr(i + 1), child)) return true;
                }
                return false;
            } else {
                int idx = c - 'a';
                if (!node->child[idx]) return false;
                node = node->child[idx];
            }
        }
        return node->is_end;
    }

    Node* root;
};
