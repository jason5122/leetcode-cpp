#include "debugging.h"
#include "leetcode.h"
using namespace std;

// Trivial approach. We expand around the center at each index.
// https://cp-algorithms.com/string/manacher.html#trivial-algorithm
vector<int> trivial(string s) {
    int n = s.size();
    s = "^" + s + "$";

    // Store longest palindrome length at each index.
    vector<int> len(n + 2);
    for (int i = 1; i <= n; ++i) {
        while (s[i - len[i]] == s[i + len[i]]) {
            ++len[i];
        }
    }
    return vector<int>(len.begin() + 1, len.end() - 1);
}

int main() {
    vector<int> result;

    result = trivial("abcba");
    cerr << result << '\n';
}
