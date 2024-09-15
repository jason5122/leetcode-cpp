/*
[2,5,9,6,9,3,8,9,7,1]
2 -> 9 -> 1 -> 5 -> 3 -> 6 -> 8 -> 7 -> (9)

2 2
9 1
1 3
5 8
3 9
6 5
8 6
7 7

2 7
9 9

[3,1,3,4,2]
3 -> 4 -> 2 -> (3)

3 3
4 2
2 4
3 3

3 3

n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Find where slow and fast meet.
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        // Step 2: From the meeting point, walk a *new* slow pointer from the start until it meets
        // with the original slow.
        int slow2 = nums[0];
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};
