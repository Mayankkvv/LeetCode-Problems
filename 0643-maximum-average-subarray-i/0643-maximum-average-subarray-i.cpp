class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        double left = 0, right = k;
        double avg_sum = sum / k;
        while(right < nums.size()){
            sum += nums[right] - nums[left];
            avg_sum = max(avg_sum, sum/k);
            right++;
            left++;
        }
        return avg_sum;
    }
};