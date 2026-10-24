class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n,pivot);
        int left = 0, right = n-1;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                ans[left++] = nums[i];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > pivot){
                ans[right--] = nums[i];
            }
        }
        return ans;
    }
};