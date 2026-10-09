class Solution {
private:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev + 1];
        int notpick = 0 + f(i+1, prev, nums, dp);
        int pick = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev]){
            pick = 1 + f(i+1, i, nums, dp); 
        }
        return dp[i][prev + 1] = max(notpick, pick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};