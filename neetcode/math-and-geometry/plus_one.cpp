/*
n == digits.size()
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int remainder = 1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + remainder;
            digits[i] = sum % 10;
            remainder = sum / 10;
        }
        if (remainder > 0) {
            digits.insert(digits.begin(), remainder);
        }
        return digits;
    }
};
