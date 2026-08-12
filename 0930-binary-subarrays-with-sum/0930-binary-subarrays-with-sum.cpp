class Solution {
private:
    int f(vector<int>& nums,int goal){
        int l = 0, r= 0, cnt = 0, sum = 0;
        if(goal < 0) return 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal -1);
        //f(nums , goal) -> returns the number of subarray where the sum is smaller than goal
        //f(nums , goal -1) -> returns the number of subarray where the sum is smaller than goal - 1
    }
};