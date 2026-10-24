class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return ;
        int low = 0, high = 1;
        while(high < nums.size()){
            if(nums[low] == 0 && nums[high] != 0){
                swap(nums[low], nums[high]);
                low++;
                high++;
            }else if(nums[low] != 0){
                low++;
                high++;
            }else{
                high++;
            }
        }
    }
};