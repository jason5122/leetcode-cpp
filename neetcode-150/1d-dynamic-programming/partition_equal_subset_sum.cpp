/*
NOT DYNAMIC PROGRAMMING
TIME LIMIT EXCEEDED
n == nums.size()
sum = accumulate(nums)
runtime: O(n*sum)
space: O(n*sum)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        this->total = accumulate(nums.begin(), nums.end(), 0);
        return helper(0, 0);
    }

private:
    vector<int> nums;
    int total;
    unordered_map<int, unordered_map<int, bool>> memo;

    int helper(int i, int sum) {
        if (i == nums.size()) return sum == total - sum;
        if (memo.count(i) && memo[i].count(sum)) return memo[i][sum];

        return memo[i][sum] = helper(i + 1, sum + nums[i]) || helper(i + 1, sum);
    }
};

/*
dp[i][j] = dp[i + 1][j] || dp[i + 1][j - nums[i]]

nums = [1,5,11,5]
sum = 22

1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0
1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0

nums = [1,2,5]
sum = 8
1,0,1,1,0,1,0,1,1
1,0,1,0,0,1,0,1,0
1,0,0,0,0,1,0,0,0
1,0,0,0,0,0,0,0,0

n == nums.size()
sum = accumulate(nums)
runtime: O(n*sum)
space: O(n*sum)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        if (sum % 2 == 1) return false;

        // Base case.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill in sub-problems.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j - nums[i]];
                }
            }
        }

        return dp[0][sum / 2];
    }
};

/*
USED SOLUTION
NOT DYNAMIC PROGRAMMING
n == nums.size()
sum = accumulate(nums)
runtime: O(n*sum)
space: O(n*sum)
*/
class Solution {
public:
    using Memo = vector<vector<optional<bool>>>;

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        this->nums = nums;
        sum = accumulate(nums.begin(), nums.end(), 0);
        memo = Memo(n + 1, vector<optional<bool>>(sum + 1, nullopt));

        if (sum % 2 == 1) return false;

        return helper(0, 0);
    }

private:
    vector<int> nums;
    int sum;
    Memo memo;

    bool helper(int i, int j) {
        if (i == nums.size()) return j == sum / 2;
        if (memo[i][j]) return *memo[i][j];

        bool result = helper(i + 1, j + nums[i]) || helper(i + 1, j);
        memo[i][j] = result;
        return result;
    }
};
