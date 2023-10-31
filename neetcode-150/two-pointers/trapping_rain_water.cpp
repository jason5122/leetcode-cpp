/*
TODO: solve this problem using two pointer

     █
█    █
█  █ █
██ ███
██ ███



       █
   █   ██ █
 █ ██ ██████
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;

        int l = 0;
        int r = 1;
        int floor = height[l];
        while (r < height.size()) {
            if (height[r] > height[r - 1]) {
                if (height[l] > floor) {
                    int w = r - l - 1;
                    int h = min(height[l], height[r]) - floor;
                    total += w * h;
                }

                if (l > 0 && height[l] < height[r] && height[l] < height[l - 1]) {
                    floor = height[l];
                    l--;
                } else {
                    l = r;
                    floor = height[l];
                    r++;
                }
            } else {
                l = r;
                floor = height[l];
                r++;
            }
        }
        return total;
    }
};
