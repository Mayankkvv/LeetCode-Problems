class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += nums[i];
        }
        int leftsum = 0;
        for (int i = 0; i < n; i++) {
            int rightsum = tot - leftsum - nums[i];
            if (rightsum == leftsum) {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};