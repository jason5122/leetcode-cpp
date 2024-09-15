#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
1 1 -> 3 5
1 2
3 2
3 5

1 1 -> 2 2
1 2
3 2 OR 1 3

1 1 -> 10 9
1 2
1 9
10 9

1 1 -> 7 10
1 3
4 3
7 3
7 10

2 3 -> 7 10
5 2
5 7
5 12

2 5
7 5
7 12

2 11

runtime: O(2^(tx+ty))
space: O(tx*ty)
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return true;
        if (sx > tx || sy > ty) return false;

        return reachingPoints(sx, sy + sx, tx, ty) || reachingPoints(sx + sy, sy, tx, ty);
    }
};

/*
USED SOLUTION

1 1 -> 3 5

3 5
3 2
1 2
1 1

1 1 -> 2 2

2 2
0 2

runtime: O(max(tx, ty))
space: O(1)
*/
class Solution2 {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;

            if (tx > ty) tx -= ty;
            else ty -= tx;
        }
        return false;
    }
};

/*
USED SOLUTION
*/
class Solution3 {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;

            if (tx > ty) tx -= ty;
            else ty -= tx;
        }
        return false;
    }
};

int main() {
    cout << boolalpha;

    Solution2 solution;
    int sx, sy, tx, ty;
    bool ans;

    solution = Solution2();
    sx = 1, sy = 1, tx = 3, ty = 5;
    ans = solution.reachingPoints(sx, sy, tx, ty);
    cout << ans << '\n';  // true

    solution = Solution2();
    sx = 1, sy = 1, tx = 2, ty = 2;
    ans = solution.reachingPoints(sx, sy, tx, ty);
    cout << ans << '\n';  // false

    solution = Solution2();
    sx = 1, sy = 1, tx = 1, ty = 1;
    ans = solution.reachingPoints(sx, sy, tx, ty);
    cout << ans << '\n';  // true
}
