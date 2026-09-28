class Solution {
private:
    int f(int i, int sum, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i == coins.size()) return 0;
        if(sum > target) return 0;
        if(sum == target) return 1;
        if(dp[i][sum] != -1) return dp[i][sum];
        int picksame = f(i, sum +  coins[i], target, coins, dp);
        int notsame = f(i+1, sum, target, coins, dp);
        return dp[i][sum] = picksame + notsame;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(0,0, amount, coins, dp);
    }
};