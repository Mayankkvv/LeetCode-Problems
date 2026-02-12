class Solution {
private:
    int first(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size() -1;
        int mid = 0;
        int f =-1;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                f = mid;
                end = mid -1;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid -1;
        }
        return f;
    }

    int last(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size() -1;
        int mid = 0;
        int l =-1;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                l = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid -1;
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lastIndex = last(nums , target);
        int firstIndex = first(nums, target);
        vector<int> ans;
        ans.push_back(firstIndex);
        ans.push_back(lastIndex);
        return ans;
    }
};