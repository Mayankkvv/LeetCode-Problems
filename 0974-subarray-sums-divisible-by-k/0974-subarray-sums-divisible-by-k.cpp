
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int subarr = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            subarr += nums[i];
            int rem = ((subarr % k) + k) % k;
            auto it = mpp.find(rem);
            if(it != mpp.end()){
                cnt += it->second;
            }
            mpp[rem]++;
        }
        return cnt;
    }
};
