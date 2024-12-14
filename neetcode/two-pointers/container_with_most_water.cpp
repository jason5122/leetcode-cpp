/*
n == height.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;

        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            max_area = max(w * h, max_area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};
