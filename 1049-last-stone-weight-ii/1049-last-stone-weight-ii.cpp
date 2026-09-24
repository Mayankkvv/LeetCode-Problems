class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= target; j++) {
                int take = 0;
                if(stones[i] <= j) {
                    take = stones[i] + dp[i + 1][j - stones[i]];
                }
                int nottake = dp[i + 1][j];
                dp[i][j] = max(take, nottake);
            }
        }
        int s1 = dp[0][target];
        int s2 = sum - s1;
        return s2 - s1;  //we want S1 to be as close as possible to totalSum / 2
    }
};