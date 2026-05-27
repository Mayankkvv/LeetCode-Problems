class Solution {
// private: 
//     int f(int ind, vector<int>& nums, vector<int>& dp){
//         if(ind == 0) return nums[ind];
//         if(ind < 0) return 0;
//         if(dp[ind] != -1) return dp[ind];
//         int pick = nums[ind] + f(ind - 2, nums, dp);
//         int notPick = 0 + f(ind - 1, nums, dp);
//         return dp[ind] = max(pick, notPick);
//     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int> dp(n , -1);
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i< n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2; 
            int notpick = 0 + prev;
            int curi = max(pick , notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};