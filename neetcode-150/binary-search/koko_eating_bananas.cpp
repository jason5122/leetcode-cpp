/*
n == piles.size()
k == max # in piles
runtime: O(lg(k)*n)
space: O(1)
*/
class Solution {
    bool is_valid_k(vector<int>& piles, int h, int k) {
        int time = 0;
        for (int pile : piles) {
            if (pile <= k) {
                time += 1;
            } else {
                time += pile / k;
                if (pile % k != 0) time += 1;
            }

            if (time > h) return false;
        }
        return time <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;
        while (low <= high) {
            int k = (high + low) / 2;
            if (is_valid_k(piles, h, k)) {
                ans = min(k, ans);
                high = k - 1;  // continue searching for smaller k
            } else {
                low = k + 1;
            }
        }
        return ans;
    }
};
