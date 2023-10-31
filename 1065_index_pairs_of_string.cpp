#include <iostream>
#include <map>
#include <vector>
using namespace std;

// n == text.length()
// m == words.size()
// w == length of word
// runtime: O(n*m*w)
// space: O(1)
vector<vector<int>> index_pairs(string text, vector<string>& words) {
    vector<vector<int>> result;

    for (const string& word : words) {
        size_t pos = text.find(word, 0);
        while (pos != string::npos) {
            int start = pos;
            int end = pos + word.length() - 1;
            result.push_back({start, end});
            pos = text.find(word, pos + 1);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

class Trie {
   public:
    map<char, Trie*> next = {};
    bool is_word = false;

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
};

// USED SOLUTION
// n == text.length()
// m == words.size()
// w == length of word
// runtime: O(n^2)
// space: O(m*w)
vector<vector<int>> index_pairs2(string text, vector<string>& words) {
    vector<vector<int>> result;

    Trie* trie = new Trie();
    for (const string& word : words) trie->insert(word);

    for (int i = 0; i < text.length(); i++) {
        Trie* node = trie;
        for (int j = i; j < text.length(); j++) {
            char ch = text[j];
            if (!node->next.count(ch)) break;

            node = node->next[ch];
            if (node->is_word) result.push_back({i, j});
        }
    }

    delete trie;
    return result;
}

int main() {
    string text = "thestoryofleetcodeandme";
    vector<string> words = {"story", "fleet", "leetcode"};
    vector<vector<int>> result = index_pairs2(text, words);
    for (vector<int> pairs : result) {
        cout << pairs[0] << ", " << pairs[1] << '\n';
    }
    cout << '\n';

    text = "ababa";
    words = {"aba", "ab"};
    result = index_pairs2(text, words);
    for (vector<int> pairs : result) {
        cout << pairs[0] << ", " << pairs[1] << '\n';
    }
    cout << '\n';
}
