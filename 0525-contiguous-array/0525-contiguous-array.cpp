class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        replace(arr.begin(), arr.end(), 0, -1);
        int k = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int prefix = 0,best = 0;
        for(int i = 0; i < n; i++){
            prefix += arr[i];
            auto it = mpp.find(prefix - k);
            if(it != mpp.end()) best = max(best , i - it-> second);
            if(!mpp.count(prefix)) mpp[prefix] = i;
        } 
        return best;
    }
};