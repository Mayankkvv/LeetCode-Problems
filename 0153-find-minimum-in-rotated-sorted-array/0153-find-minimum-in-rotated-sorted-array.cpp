class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, ans = INT_MAX, mid = 0;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[start] <= nums[mid]){
                ans = min(nums[start], ans);
                start = mid + 1;
            }
            else{
                ans = min(nums[mid], ans);
                end = mid - 1;
            }
        }
        return ans;
    }
};