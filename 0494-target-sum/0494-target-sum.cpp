class Solution {
private:
    int f(int i, int sum, vector<int>& nums, int target) {
        if(i == nums.size()) {
            if(sum == target)
                return 1;
            return 0;
        }

        int add = f(i + 1, sum + nums[i], nums, target);

        int subtract = f(i + 1, sum - nums[i], nums, target);

        return add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0, 0, nums, target);
    }
};