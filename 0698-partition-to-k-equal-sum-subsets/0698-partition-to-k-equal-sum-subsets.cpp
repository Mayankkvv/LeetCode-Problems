class Solution {
private:
    bool f(int start,
           vector<int>& nums,
           vector<bool>& used,
           int k,
           int currsum,
           int target,
           unordered_map<string, bool>& dp) {

        // One subset completed
        if (currsum == target) {

            // Last subset automatically valid
            if (k == 1)
                return true;

            return f(0, nums, used,
                     k - 1, 0, target, dp);
        }

        // Create state string
        string state = "";

        for (bool x : used) {
            state += (x ? '1' : '0');
        }

        state += "|" + to_string(currsum)
                 + "|" + to_string(k);

        // Memoization
        if (dp.count(state))
            return dp[state];

        for (int i = start; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Exceeds target
            if (currsum + nums[i] > target)
                continue;

            used[i] = true;

            if (f(i + 1,
                  nums,
                  used,
                  k,
                  currsum + nums[i],
                  target,
                  dp))
                return dp[state] = true;

            // Backtrack
            used[i] = false;
        }

        return dp[state] = false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total = 0;

        for (int x : nums)
            total += x;

        // Impossible
        if (total % k != 0)
            return false;

        int target = total / k;

        vector<bool> used(nums.size(), false);

        unordered_map<string, bool> dp;

        return f(0, nums, used,
                 k, 0, target, dp);
    }
};