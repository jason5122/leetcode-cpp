#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == moves.length()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char ch : moves) {
            if (ch == 'U') y++;
            if (ch == 'D') y--;
            if (ch == 'R') x++;
            if (ch == 'L') x--;
        }
        return x == 0 && y == 0;
    }
};

int main() {
    cout << boolalpha;

    Solution solution;
    string moves;
    bool ans;

    solution = Solution();
    moves = "UD";
    ans = solution.judgeCircle(moves);
    cout << ans << '\n';  // true

    solution = Solution();
    moves = "LL";
    ans = solution.judgeCircle(moves);
    cout << ans << '\n';  // false
}
