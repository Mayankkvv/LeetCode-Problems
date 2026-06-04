class Solution {
private:
    int f(int i, vector<int>& coins, int target, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int notpick = f(i - 1, coins, target, dp);
        int pick = 1e9;
        if (target >= coins[i]) {
            pick = 1 + f(i, coins, target - coins[i], dp);
        }
        return dp[i][target] = min(pick, notpick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, coins, amount, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};