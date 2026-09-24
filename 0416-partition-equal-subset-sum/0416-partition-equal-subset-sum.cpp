class Solution {
private:
    bool f(int i, int target, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i >= n) return false;
        if(i == n-1) return (target == nums[n-1]);
        if(dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if(nums[i] <= target){
            take = f(i+1, target-nums[i], nums, n, dp);
        }
        bool nottake = f(i+1, target, nums, n, dp);
        return dp[i][target] = take||nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, -1));
        return f(0, sum/2, nums,n,dp);
    }
};