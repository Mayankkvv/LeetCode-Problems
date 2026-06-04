class Solution {
private:
    int f(int i, int n, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return 0;
        if (i == n)
            return -1e9;
        if(dp[i][target] != -1) return dp[i][target];
        int pick = -1e9;
        if (nums[i] <= target) {
            pick = 1 + f(i + 1, n, nums, target - nums[i], dp);
        }
        int notpick = f(i + 1, n, nums, target, dp);
        return dp[i][target] =  max(pick, notpick);
    }

public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ans = f(0, n, nums, target,dp);
        return (ans < 0) ? -1 : ans;
    }
};