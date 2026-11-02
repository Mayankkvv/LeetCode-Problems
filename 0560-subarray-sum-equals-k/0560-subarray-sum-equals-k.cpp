class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        mpp[0] = 1;
        int prefix = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            auto it = mpp.find(prefix - k);
            if(it != mpp.end()) count += it -> second;
            mpp[prefix]++;
        }
        return count;
    }
};