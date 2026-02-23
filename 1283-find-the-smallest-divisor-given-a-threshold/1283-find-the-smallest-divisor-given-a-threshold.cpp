class Solution {
private:
    int f(vector<int>& nums, int mid){
        int cnt =0;
        for(int i = 0; i < nums.size(); i++){
            cnt += ceil((double)nums[i]/(double)mid); // fixed
        }
        return cnt;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int start = 1, end = INT_MIN, ans = 0; // fixed start
       for(int i = 0; i < nums.size(); i++){
        end = max(nums[i], end);
       } 
       while(start <= end){
        int mid = start + (end-start)/2;
        if(f(nums, mid) <= threshold){
            ans = mid;
            end = mid - 1;   // fixed direction
        }
        else{
            start = mid + 1; // fixed direction
        }
       }
       return ans;
    }
};