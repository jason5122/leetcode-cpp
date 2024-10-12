/*
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int k = 1;
        while (n >= k) {
            ans++;
            n -= k;

            k++;
        }
        return ans;
    }
};

/*
USED PARTIAL SOLUTION
runtime: O(lg(n))
space: O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        while (l <= r) {
            int m = (l + r) / 2;

            long sum = ((long)m * (m + 1)) / 2;  // Formula for 1+2+3+4+...+m.
            if (sum < n) {
                l = m + 1;
            } else if (sum > n) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return r;
    }
};

/*
USED SOLUTION
runtime: O(1)
space: O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        // Completing the square.
        return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};
