class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int ind = -1;

        // Step 1: Find the breakpoint
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                ind = i - 1;
                break;
            }
        }

        // Step 2: Swap with the just larger element
        if(ind != -1){
            for(int i = n - 1; i > ind; i--){
                if(nums[i] > nums[ind]){
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};