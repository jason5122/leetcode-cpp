/*
n == time.size()
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> complement;

        int ans = 0;
        for (int t : time) {
            int mod = t % 60;

            if (complement.count(mod)) {
                ans += complement[mod];
            }
            complement[(60 - mod) % 60] += 1;
        }
        return ans;
    }
};
