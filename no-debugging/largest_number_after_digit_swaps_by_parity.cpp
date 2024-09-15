/*
n == # of digits in num
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int, vector<int>, greater<int>> even;
        priority_queue<int, vector<int>, greater<int>> odd;

        queue<bool> parity_list;  // `true` represents even.
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (digit % 2 == 0) {
                even.push(digit);
                parity_list.push(true);
            } else {
                odd.push(digit);
                parity_list.push(false);
            }
        }

        int ans = 0;
        int e = 0;
        while (!parity_list.empty()) {
            bool is_even = parity_list.front();
            parity_list.pop();

            int k = is_even ? even.top() : odd.top();
            is_even ? even.pop() : odd.pop();

            ans += k * int(pow(10, e));

            e++;
        }
        return ans;
    }
};
