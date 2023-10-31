#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == instructions.length()
runtime: O(4n)
space: O(1)
*/
class Solution {
    int calculate_turn(int direction, char turn) {
        if (turn == 'R') direction++;
        if (turn == 'L') direction--;

        if (direction >= 4) direction -= 4;
        if (direction < 0) direction += 4;
        return direction;
    }

public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int direction = 0;  // 0 = N, 1 = E, 2 = S, 3 = W

        for (int i = 0; i < 4; i++) {
            for (char ch : instructions) {
                if (ch == 'L' || ch == 'R') {
                    direction = calculate_turn(direction, ch);
                } else {
                    if (direction == 0) y++;
                    if (direction == 1) x++;
                    if (direction == 2) y--;
                    if (direction == 3) x--;
                }
            }
            if (x == 0 && y == 0) return true;
        }
        return false;
    }
};

/*
USED SOLUTION
n == instructions.length()
runtime: O(n)
space: O(1)
*/
class Solution {
    int calculate_turn(int direction, char turn) {
        if (turn == 'R') direction++;
        if (turn == 'L') direction--;

        if (direction >= 4) direction -= 4;
        if (direction < 0) direction += 4;
        return direction;
    }

public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int direction = 0;  // 0 = N, 1 = E, 2 = S, 3 = W

        for (char ch : instructions) {
            if (ch == 'L' || ch == 'R') {
                direction = calculate_turn(direction, ch);
            } else {
                if (direction == 0) y++;
                if (direction == 1) x++;
                if (direction == 2) y--;
                if (direction == 3) x--;
            }
        }
        return x == 0 && y == 0 || direction != 0;
    }
};

int main() {
    cout << boolalpha;

    Solution solution;
    string instructions;
    bool ans;

    solution = Solution();
    instructions = "GGLLGG";
    ans = solution.isRobotBounded(instructions);
    cout << ans << '\n';  // true

    solution = Solution();
    instructions = "GG";
    ans = solution.isRobotBounded(instructions);
    cout << ans << '\n';  // false

    solution = Solution();
    instructions = "GL";
    ans = solution.isRobotBounded(instructions);
    cout << ans << '\n';  // true
}
