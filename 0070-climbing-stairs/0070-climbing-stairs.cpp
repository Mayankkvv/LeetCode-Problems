class Solution {
private:
    int f(int n, vector<int>& dp) {
        // Base cases
        if (n == 0 || n == 1) return 1;

        // If already calculated, return stored value
        if (dp[n] != -1) return dp[n];

        // Store and return result
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};