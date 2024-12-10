/*
arr = [1,1,2,2,3,3,4,4,5,5], target = 8

arr = [1,1,2,2,2,2], target = 5

Two sum:
[1,2,2,2,2], new_target = 4

[1,2,2,2,2]
*/

/*
n == arr.size()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int new_target = target - arr[i];
            unordered_map<int, long> hmap;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                int complement = new_target - arr[j];
                if (hmap.count(complement)) {
                    ans += hmap[complement];
                }
                hmap[arr[j]]++;
            }
        }
        return (ans / 3) % kMod;
    }

private:
    static constexpr long kMod = 1e9 + 7;
};

/*
n == arr.size()
runtime: O(n^2)
space: O(n)
*/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int new_target = target - arr[i];
            unordered_map<int, long> hmap;
            for (int j = i + 1; j < n; j++) {
                int complement = new_target - arr[j];
                if (hmap.count(complement)) {
                    ans += hmap[complement];
                }
                hmap[arr[j]]++;
            }
        }
        return ans % kMod;
    }

private:
    static constexpr long kMod = 1e9 + 7;
};
