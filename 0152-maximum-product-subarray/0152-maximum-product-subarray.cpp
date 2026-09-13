class Solution {
private:
    int f(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i == n) return INT_MIN;
        if(dp[i] != -1) return dp[i];
        int pro = 1;
        int ans = INT_MIN;
        for(int j = i; j < n; j++){
            pro *= nums[j];
            ans = max(ans, pro);
        }
        return dp[i] = max(ans, f(i+1, n, nums, dp));
    }
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[n] = -1e9;
        for(int i = 0; i < n; i++){
            int pro = 1;
            int ans = INT_MIN;
            for(int j = i; j < n; j++){
                pro *= nums[j];
                ans = max(ans, pro);
            }
            dp[i] = ans;
        }
        int fin = INT_MIN;
        for(int i = 0; i <= n; i++){
            fin = max(fin, dp[i]);
        }
        return fin;
    }
};