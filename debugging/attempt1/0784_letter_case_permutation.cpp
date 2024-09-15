#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<string> result;

    void helper(string& s, int i) {
        if (i == s.length()) {
            result.push_back(s);
            return;
        }
        if (!isalpha(s[i])) {
            helper(s, i + 1);
            return;
        }

        if (isupper(s[i])) {
            helper(s, i + 1);
            s[i] = tolower(s[i]);
            helper(s, i + 1);
        } else {
            helper(s, i + 1);
            s[i] = toupper(s[i]);
            helper(s, i + 1);
        }
    }

public:
    // n == s.length()
    // runtime: O(2^n)
    // space: O(2^n)
    vector<string> letter_case_permutation(string s) {
        helper(s, 0);
        return result;
    }
};

int main() {
    Solution s1;
    string s = "a1b2";
    vector<string> result = s1.letter_case_permutation(s);
    // ["a1b2","a1B2","A1b2","A1B2"]
    for (string str : result) cout << str << '\n';
    cout << '\n';

    Solution s2;
    s = "3z4";
    result = s2.letter_case_permutation(s);  // ["3z4","3Z4"]
    for (string str : result) cout << str << '\n';
    cout << '\n';
}
