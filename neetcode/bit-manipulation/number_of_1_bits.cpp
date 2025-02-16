/*
runtime: O(32)
space: O(1)

There are 32 bits at maximum in an int.
*/
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};

/*
USED SOLUTION
runtime: O(32)
space: O(1)

There are 32 bits at maximum in an int.
*/
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n) {
            ans++;
            // Flip least-significant 1-bit to 0.
            n &= n - 1;
        }
        return ans;
    }
};
