/*
runtime: O(lg(n))
space: O(1)
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
