class Solution {
private:
    int f(vector<int>& nums, int k, int mid){
        int ans = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                ans+=1;
                sum = nums[i];
            }
        }
        return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0); 
        while(low<=high){
            int mid = low + (high-low)/2;
            int ans = f(nums , k, mid);
            if(ans > k) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};