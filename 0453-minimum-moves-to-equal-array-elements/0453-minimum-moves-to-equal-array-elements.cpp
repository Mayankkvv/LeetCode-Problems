class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mn = min(mn, nums[i]);
        }
        return sum - (long long)nums.size() * mn;
    }
};