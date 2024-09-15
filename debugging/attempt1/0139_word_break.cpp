#include "debugging.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// n == s.length()
// runtime: O(n*2^(n-1))?
// space: O(2^n)?
class Solution {
    string s;
    unordered_set<string> word_dict;

    bool backtrack(int i) {
        if (i == s.length()) return true;

        for (int count = 1; count < s.length() - i + 1; count++) {
            if (word_dict.count(s.substr(i, count))) {
                bool result = backtrack(i + count);

                if (result) return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        word_dict = unordered_set(wordDict.begin(), wordDict.end());

        return backtrack(0);
    }
};

// USED SOLUTION
// n == s.length()
// runtime: O(n^3)
class Solution2 {
    string s;
    unordered_set<string> word_dict;
    unordered_set<int> memo;

    bool backtrack(int i) {
        if (memo.count(i)) return false;
        if (i == s.length()) return true;

        for (int count = 1; count < s.length() - i + 1; count++) {
            if (word_dict.count(s.substr(i, count))) {
                bool result = backtrack(i + count);

                if (result) return true;
                else memo.insert(i);
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        word_dict = unordered_set(wordDict.begin(), wordDict.end());

        return backtrack(0);
    }
};

// USED SOLUTION
// n == s.length()
// runtime: O(n^3)
class Solution3 {
    string s;
    unordered_set<string> word_dict;
    unordered_map<int, bool> cache;

    bool cached_split(int i) {
        if (cache.count(i)) return cache[i];

        cache[i] = split(i);
        return cache[i];
    }

    bool split(int i) {
        if (i == s.length()) return true;

        for (int count = 1; count < s.length() - i + 1; count++) {
            if (word_dict.count(s.substr(i, count))) {
                bool result = cached_split(i + count);

                if (result) return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        word_dict = unordered_set(wordDict.begin(), wordDict.end());

        return split(0);
    }
};

// USED SOLUTION
// n == s.length()
// m == wordDict.size()
// k == average length of word in wordDict
// runtime: O(n^3+m*k)
// space: O(n+m*k)
class Solution4 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        queue<int> queue;
        vector<bool> seen(s.length(), false);

        queue.push(0);
        seen[0] = true;
        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();

            if (start == s.length()) return true;

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) continue;

                string word = s.substr(start, end - start);

                if (words.count(word)) {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }
        return false;
    }
};

/*
n == s.length()
m == wordDict.size()
k == average length of word in wordDict

runtime: O(n^3+m*k)
    O(m*k) converting wordDict into a set
    O(n^2) nested for loops
        O(n) create substring
space: O(n+m*k)
    O(n) DP array
    O(m*k) set
*/
class Solution5 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.length() + 1, false);

        dp[0] = true;
        for (int start = 0; start < s.length(); start++) {
            if (!dp[start]) continue;

            for (int end = start + 1; end <= s.length(); end++) {
                string word = s.substr(start, end - start);

                if (words.count(word)) dp[end] = true;
            }
        }
        return dp.back();
    }
};

int main() {
    bool result;
    Solution5 soln;
    string s;
    vector<string> wordDict;

    soln = Solution5();
    s = "leetcode";
    wordDict = {"leet", "code"};
    result = soln.wordBreak(s, wordDict);
    cout << result << '\n';  // true

    soln = Solution5();
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    result = soln.wordBreak(s, wordDict);
    cout << result << '\n';  // true

    soln = Solution5();
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = soln.wordBreak(s, wordDict);
    cout << result << '\n';  // false

    // USED SOLUTION
    soln = Solution5();
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordDict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    result = soln.wordBreak(s, wordDict);
    cout << result << '\n';  // false
}
