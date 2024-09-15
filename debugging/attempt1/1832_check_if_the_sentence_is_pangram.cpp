#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == sentence.length()
runtime: O(n)
space: O(26)
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);

        int count = 0;
        for (char ch : sentence) {
            int i = ch - 'a';
            if (!seen[i]) {
                seen[i] = true;
                count++;
            }
        }
        return count == 26;
    }
};

int main() {
    cout << boolalpha;

    Solution solution;
    string sentence;
    bool ans;

    solution = Solution();
    sentence = "thequickbrownfoxjumpsoverthelazydog";
    ans = solution.checkIfPangram(sentence);
    cout << ans << '\n';  // true

    solution = Solution();
    sentence = "leetcode";
    ans = solution.checkIfPangram(sentence);
    cout << ans << '\n';  // false
}
