/*
NOT MATH
n == # of numbers in happy number chain
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while (fast != 1) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast) return false;
        }
        return true;
    }

private:
    int next(int n) {
        int result = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            result += digit * digit;
        }
        return result;
    }
};
