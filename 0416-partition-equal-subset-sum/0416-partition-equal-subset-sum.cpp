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
        int target = sum/2;
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        //dp[n-1][target] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= target; j++){
                bool take = false;
                if(nums[i] <= j){
                take = dp[i+1][j-nums[i]];
                }
                bool nottake = dp[i+1][j];
                dp[i][j] = take||nottake;
            }
        }
        return dp[0][target];
    }
};