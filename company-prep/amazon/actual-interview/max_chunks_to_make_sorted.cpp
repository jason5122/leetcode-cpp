/*
n == arr.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int curr_sum = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += i;
            curr_sum += arr[i];
            if (sum == curr_sum) {
                ans++;
            }
        }
        return ans;
    }
};
