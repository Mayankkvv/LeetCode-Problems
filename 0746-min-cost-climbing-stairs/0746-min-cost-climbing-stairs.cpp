class Solution {
private:
    int f(int i, vector<int>& cost, int n, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int a = cost[i] + f(i + 1, cost, n, dp);
        int b = cost[i] + f(i + 2, cost, n, dp);
        return dp[i] = min(a, b);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(f(0,cost, n, dp) , f(1, cost, n, dp));
    }
};