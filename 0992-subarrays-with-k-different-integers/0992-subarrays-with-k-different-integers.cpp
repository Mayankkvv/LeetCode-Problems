class Solution {
private:
    int f(vector<int>& nums, int k){
        if(k < 0) return 0;
        map<int, int> mpp;
        int l = 0, r = 0, ans = 0, cnt = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k -1);
    }
};