#include "debugging.h"
#include <iostream>
using namespace std;

// m == s.length()
// n == t.length()
// runtime: O(n)
// space: O(1)
bool is_subsequence(string s, string t) {
    if (s.empty()) return true;

    int i = 0;
    for (char c : t) {
        if (s[i] == c) i++;

        if (i == s.length()) return true;
    }
    return false;
}

int main() {
    bool result;
    string s, t;

    s = "abc";
    t = "ahbgdc";
    result = is_subsequence(s, t);
    cout << result << '\n';  // true

    s = "axc";
    t = "ahbgdc";
    result = is_subsequence(s, t);
    cout << result << '\n';  // false
}
