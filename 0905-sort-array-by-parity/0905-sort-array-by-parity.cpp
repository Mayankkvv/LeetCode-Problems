class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            if(nums[low] % 2 == 1 && nums[high] % 2 == 0){
                swap(nums[low], nums[high]);
                low++;
                high--;
            }else if(nums[low] % 2 == 1 && nums[low] % 2 == 1){
                high--;
            }else{
                low++;
            }
        }
        return nums;
    }
};