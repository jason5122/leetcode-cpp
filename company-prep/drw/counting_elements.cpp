/*
n == arr.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>{});

        unordered_set<int> seen;
        int ans = 0;
        for (int n : arr) {
            seen.insert(n);

            if (seen.count(n + 1)) {
                ans++;
            }
        }
        return ans;
    }
};
