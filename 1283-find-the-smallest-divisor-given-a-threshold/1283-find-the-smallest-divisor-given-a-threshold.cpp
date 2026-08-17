class Solution {
private:
    int f(vector<int>& nums, int mid) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + mid - 1) / mid;
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        int ans = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (f(nums, mid) <= threshold) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};