#include "debugging.h"
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string& s) {
    vector<string> result;

    string word;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            result.push_back(word);
            word = "";
        } else {
            word += s[i];
        }
    }
    if (!word.empty()) result.push_back(word);
    return result;
}

// m == pattern.length()
// n == s.length()
// runtime: O(m + n)
// space: O(s)
bool word_pattern(string pattern, string s) {
    vector<string> words = split(s);

    if (words.size() != pattern.length()) return false;

    unordered_map<char, string> bijection;
    unordered_set<string> seen_words;
    for (int i = 0; i < pattern.length(); i++) {
        char letter = pattern[i];
        string& word = words[i];

        if (bijection.count(letter)) {
            if (bijection[letter] != word) return false;
        } else {
            if (seen_words.count(word)) return false;

            seen_words.insert(word);
            bijection[letter] = word;
        }
    }
    return true;
}

int main() {
    bool result;
    string pattern;
    string s;

    pattern = "abba";
    s = "dog cat cat dog";
    result = word_pattern(pattern, s);
    cout << result << '\n';  // true

    pattern = "abba";
    s = "dog cat cat fish";
    result = word_pattern(pattern, s);
    cout << result << '\n';  // false

    pattern = "aaaa";
    s = "dog cat cat dog";
    result = word_pattern(pattern, s);
    cout << result << '\n';  // false
}
