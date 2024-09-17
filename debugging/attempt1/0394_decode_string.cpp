#include "debugging.h"
#include "leetcode.h"
using namespace std;

constexpr auto operator*(std::string_view sv, int times) {
    string result;
    for (int i = 0; i < times; i++) {
        result += sv;
    }
    return result;
}
constexpr auto operator*(int times, std::string_view sv) {
    return sv * times;
}

/*
n == s.length()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    string decodeString(string s) {
        string ans;

        int n = s.length();
        int i = 0;
        while (i < n) {
            if (isalpha(s[i])) {
                ans += s[i];
            } else if (isdigit(s[i])) {
                string k_str;
                while (isdigit(s[i])) {
                    k_str += s[i];
                    i++;
                }

                int paren_count = 1;  // Count '[';
                i++;
                int j = i;
                while (paren_count > 0) {
                    if (s[j] == '[') {
                        paren_count++;
                    } else if (s[j] == ']') {
                        paren_count--;
                    }

                    if (paren_count > 0) j++;
                }

                // `nested` is the string between the [], excluding the braces.
                string nested = s.substr(i, j - i);
                int k = stoi(k_str);
                ans += k * decodeString(nested);

                i = j;
            }
            i++;
        }
        return ans;
    }
};

int main() {
    Solution soln;
    string s;
    string ans;

    // CUSTOM
    soln = Solution{};
    s = "2[bc]";
    ans = soln.decodeString(s);
    cerr << ans << '\n';  // bcbc

    soln = Solution{};
    s = "3[a]2[bc]";
    ans = soln.decodeString(s);
    cerr << ans << '\n';  // aaabcbc
}
