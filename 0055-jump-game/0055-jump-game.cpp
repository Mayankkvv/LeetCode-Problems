class Solution {
private:
    bool f(int start, vector<int>& nums, int end, vector<int>& dp) {

        // Reached or crossed end
        if (start >= end)
            return true;

        // Memoization
        if (dp[start] != -1)
            return dp[start];

        int jumps = nums[start];

        // Try all jumps
        for (int i = 1; i <= jumps; i++) {

            if (start + i < nums.size()) {

                if (f(start + i, nums, end, dp))
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return f(0, nums, n - 1, dp);
    }
};