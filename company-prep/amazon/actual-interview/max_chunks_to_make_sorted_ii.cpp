/*
USED HINT
n == arr.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        int n = arr.size();
        long long sum;
        vector<long long> prefix_arr(n);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prefix_arr[i] = sum;
        }

        vector<long long> prefix_sorted(n);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sorted[i];
            prefix_sorted[i] = sum;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (prefix_arr[i] == prefix_sorted[i]) {
                ans++;
            }
        }
        return ans;
    }
};

/*
n == arr.size()
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        int n = arr.size();
        long long prefix_arr = 0;
        long long prefix_sorted = 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            prefix_arr += arr[i];
            prefix_sorted += sorted[i];

            if (prefix_arr == prefix_sorted) {
                ans++;
            }
        }
        return ans;
    }
};
