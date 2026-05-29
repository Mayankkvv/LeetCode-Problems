class Solution {
private:
    bool f(int i, int n, vector<int>& nums, int target, vector<vector<int>>& dp) {

        // Subset found
        if (target == 0)
            return true;

        // Reached end
        if (i == n)
            return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool pick = false;

        if (nums[i] <= target) {

            pick = f(i + 1, n, nums, target - nums[i], dp);
        }

        bool notpick = f(i + 1, n, nums, target, dp);

        return dp[i][target] = pick || notpick;
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totsum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(totsum + 1, -1));

        // Odd sum cannot be partitioned
        if (totsum % 2 == 1)
            return false;

        return f(0, n, nums, totsum / 2,dp);
    }
};