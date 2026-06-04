class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums,
                                   int target) {

        int n = nums.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, -1e9));

        dp[n][0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            for(int t = 0; t <= target; t++) {

                int notpick =
                    dp[i + 1][t];

                int pick = -1e9;

                if(nums[i] <= t) {

                    pick =
                        1 + dp[i + 1]
                               [t - nums[i]];
                }

                dp[i][t] =
                    max(pick, notpick);
            }
        }

        int ans = dp[0][target];

        return (ans < 0) ? -1 : ans;
    }
};