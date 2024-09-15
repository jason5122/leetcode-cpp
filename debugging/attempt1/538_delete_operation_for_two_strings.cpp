#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
algorithm
altruistic

rithm
truistic
+2

ithm
truistic
+1

ithm
ruistic
+2

ithm
istic
+1

thm
stic

thm
tic
+1

""
""
+4

answer? = alit
actual answer? = alrit
*/
class Solution {
    void decrement(unordered_map<char, int>& counts, unordered_map<char, queue<int>>& indexes,
                   char ch) {
        counts[ch]--;
        if (counts[ch] == 0) counts.erase(ch);
        indexes[ch].pop();
        if (indexes[ch].empty()) indexes.erase(ch);
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        unordered_map<char, int> counts1;
        unordered_map<char, int> counts2;
        unordered_map<char, queue<int>> indexes1;
        unordered_map<char, queue<int>> indexes2;

        for (int i = 0; i < m; i++) {
            counts1[word1[i]]++;
            indexes1[word1[i]].push(i);
        }
        for (int i = 0; i < n; i++) {
            counts2[word2[i]]++;
            indexes2[word2[i]].push(i);
        }

        int i = 0;  // word1
        int j = 0;  // word2
        int ans = 0;
        while (i < m && j < n) {
            if (counts2.count(word1[i]) && counts1.count(word2[j])) {
                if (word1[i] == word2[j]) {
                    decrement(counts1, indexes1, word1[i]);
                    decrement(counts2, indexes2, word2[j]);
                    ++i;
                    ++j;
                }
                // tiebreak based on earliest next occurrence
                else {
                    int idx1 = indexes2[word1[i]].front() - i;
                    int idx2 = indexes1[word2[j]].front() - j;

                    if (idx1 <= idx2) {
                        decrement(counts2, indexes2, word2[j]);
                        j++;
                        ++ans;
                    } else {
                        decrement(counts1, indexes1, word1[i]);
                        i++;
                        ++ans;
                    }
                }
            } else {
                if (!counts2.count(word1[i])) {
                    decrement(counts1, indexes1, word1[i]);
                    ++i;
                    ++ans;
                }
                if (!counts1.count(word2[j])) {
                    decrement(counts2, indexes2, word2[j]);
                    ++j;
                    ++ans;
                }
            }
        }

        if (i < m) ans += m - i;
        if (j < n) ans += n - j;

        return ans;
    }
};

class Solution2 {
    string word1;
    string word2;
    unordered_map<char, int> counts1;
    unordered_map<char, int> counts2;
    unordered_map<int, unordered_map<int, int>> cache;

    int backtrack_cached(int i, int j) {
        if (cache.count(i) && cache[i].count(j)) return cache[i][j];
        else {
            int result = backtrack(i, j);
            cache[i][j] = result;
            return result;
        }
    }

    int backtrack(int i, int j) {
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;

        int result;
        if (word1[i] == word2[j]) {
            counts1[word1[i]]--;
            if (counts1[word1[i]] == 0) counts1.erase(word1[i]);
            counts2[word2[j]]--;
            if (counts2[word2[j]] == 0) counts2.erase(word2[j]);
            result = backtrack_cached(i + 1, j + 1);
            counts1[word1[i]]++;
            counts2[word2[j]]++;
        } else if (!counts2.count(word1[i])) {
            counts1[word1[i]]--;
            if (counts1[word1[i]] == 0) counts1.erase(word1[i]);
            result = 1 + backtrack_cached(i + 1, j);
            counts1[word1[i]]++;
        } else if (!counts1.count(word2[j])) {
            counts2[word2[j]]--;
            if (counts2[word2[j]] == 0) counts2.erase(word2[j]);
            return 1 + backtrack_cached(i, j + 1);
            counts2[word2[j]]++;
        } else {
            counts1[word1[i]]--;
            if (counts1[word1[i]] == 0) counts1.erase(word1[i]);
            result = 1 + backtrack_cached(i + 1, j);
            counts1[word1[i]]++;

            counts2[word2[j]]--;
            if (counts2[word2[j]] == 0) counts2.erase(word2[j]);
            result = min(1 + backtrack_cached(i, j + 1), result);
            counts2[word2[j]]++;
        }
        return result;
    }

public:
    int minDistance(string word1, string word2) {
        for (char ch : word1) counts1[ch]++;
        for (char ch : word2) counts2[ch]++;
        this->word1 = word1;
        this->word2 = word2;

        return backtrack(0, 0);
    }
};

/*
USED SOLUTION
m == word1.length()
n == word2.length()
runtime: O(2^max(m,n))
space: O(max(m,n))
*/
class Solution3 {
    int lcs(string& word1, string& word2, int m, int n) {
        if (m == 0 || n == 0) return 0;

        if (word1[m - 1] == word2[n - 1]) {
            return 1 + lcs(word1, word2, m - 1, n - 1);
        } else {
            return max(lcs(word1, word2, m - 1, n), lcs(word1, word2, m, n - 1));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        return m + n - 2 * lcs(word1, word2, m, n);
    }
};

/*
m == word1.length()
n == word2.length()
runtime: O(m*n)
space: O(m*n)
*/
class Solution4 {
    unordered_map<int, unordered_map<int, int>> cache;

    int lcs_cached(string& word1, string& word2, int m, int n) {
        if (cache.count(m) && cache[m].count(n)) {
            return cache[m][n];
        } else {
            int ans = lcs(word1, word2, m, n);
            cache[m][n] = ans;
            return ans;
        }
    }

    int lcs(string& word1, string& word2, int m, int n) {
        if (m == 0 || n == 0) return 0;

        if (word1[m - 1] == word2[n - 1]) {
            return 1 + lcs_cached(word1, word2, m - 1, n - 1);
        } else {
            return max(lcs_cached(word1, word2, m - 1, n), lcs_cached(word1, word2, m, n - 1));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        return m + n - 2 * lcs(word1, word2, m, n);
    }
};

int main() {
    Solution4 solution;
    string word1, word2;
    int ans;

    solution = Solution4();
    word1 = "sea";
    word2 = "eat";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 2

    solution = Solution4();
    word1 = "leetcode";
    word2 = "etco";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 4

    // USED SOLUTION
    solution = Solution4();
    word1 = "algorithm";
    word2 = "altruistic";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 9

    // USED SOLUTION
    solution = Solution4();
    word1 = "intention";
    word2 = "execution";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 8

    // USED SOLUTION
    solution = Solution4();
    word1 = "dinitrophenylhydrazine";
    word2 = "dimethylhydrazine";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 9

    // USED SOLUTION
    solution = Solution4();
    word1 = "dinitrophenylhydrazine";
    word2 = "benzalphenylhydrazone";
    ans = solution.minDistance(word1, word2);
    cout << ans << '\n';  // 13
}
