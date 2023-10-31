#include <iostream>
using namespace std;

// m == s.length()
// n == t.length()
// runtime: O(m+n)
// space: O(1)
bool backspace_compare(string s, string t) {
    int i = s.length() - 1;
    int j = t.length() - 1;

    while (i >= 0 || j >= 0) {
        int skips_s = 0;
        while (i >= 0 && (s[i] == '#' || skips_s > 0)) {
            if (s[i] == '#') {
                skips_s++;
                i--;
            } else if (skips_s > 0) {
                skips_s--;
                i--;
            }
        }
        int skips_t = 0;
        while (j >= 0 && (t[j] == '#' || skips_t > 0)) {
            if (t[j] == '#') {
                skips_t++;
                j--;
            } else if (skips_t > 0) {
                skips_t--;
                j--;
            }
        }

        // more backspaces than characters
        if (i < 0) return j < 0;
        if (j < 0) return i < 0;

        if (s[i] != t[j]) return false;
        i--;
        j--;
    }
    return true;
}

int main() {
    string s = "ab#c";
    string t = "ad#c";
    bool result = backspace_compare(s, t);  // true
    cout << result << '\n';

    s = "ab##";
    t = "c#d#";
    result = backspace_compare(s, t);  // true
    cout << result << '\n';

    s = "a#c";
    t = "b";
    result = backspace_compare(s, t);  // false
    cout << result << '\n';

    // USED SOLUTION
    s = "xywrrmp";
    t = "xywrrmu#p";
    result = backspace_compare(s, t);  // true
    cout << result << '\n';

    // USED SOLUTION
    s = "nzp#o#g";
    t = "b#nzp#o#g";
    result = backspace_compare(s, t);  // true
    cout << result << '\n';
}
