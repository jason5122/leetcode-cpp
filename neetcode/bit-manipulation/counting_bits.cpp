/*
runtime: O(n*lg(n))
space: O(1)
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(pop_count(i));
        }
        return ans;
    }

private:
    int pop_count(int n) {
        int ans = 0;
        while (n) {
            ans++;
            n &= n - 1;
        }
        return ans;
    }
};
