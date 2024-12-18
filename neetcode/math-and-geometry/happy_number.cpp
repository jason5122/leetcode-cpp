/*
NOT MATH
runtime: O(log10(n))
space: O(1)

The number of digits in a number is given by log10(n).
The cycle length is a constant.
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

/*
USED SOLUTION
runtime: O(log10(n))
space: O(1)

The number of digits in a number is given by log10(n).
The cycle length is a constant.
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle_members = {4, 16, 37, 58, 89, 145, 42, 20};
        while (n != 1) {
            n = next(n);
            if (cycle_members.count(n)) return false;
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
