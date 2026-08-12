class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int l = 0, r= 0, maxlen = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;
            if(mpp[nums[r]] <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};