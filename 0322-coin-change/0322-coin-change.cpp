class Solution {
private:
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();
        if(i == n-1){
            if(amount % coins[i] == 0){
                return amount/coins[i];
            }
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int notpick = f(i+1, amount, coins, dp);
        int pick = 1e9;
        if(amount >= coins[i]){
            pick = 1 + f(i, amount - coins[i], coins, dp);
        }
        return dp[i][amount] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(0, amount,coins, dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};