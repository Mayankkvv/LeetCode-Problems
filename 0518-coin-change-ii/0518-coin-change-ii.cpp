class Solution {
private:
    int f(int i, int n, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == n) {
            if (target == 0)
                return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int pick = 0;
        if (coins[i] <= target)
            pick = f(i, n, target - coins[i], coins, dp);
        int notpick = f(i + 1, n, target, coins, dp);
        return dp[i][target] = pick + notpick;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(0, n, amount, coins, dp);
    }
};