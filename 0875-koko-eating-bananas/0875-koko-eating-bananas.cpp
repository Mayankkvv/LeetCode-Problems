class Solution {
private:
    int findMax(vector<int>& arr){
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(maxi < arr[i]){
                maxi= arr[i];
            }
        }
        return maxi;
    }

    long long f(vector<int>& arr, int mid){
        int n = arr.size();
        long long total =0;
        for(int i = 0; i < n; i++){
            total += ceil((double)arr[i]/(double)mid);
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = findMax(piles), ans = INT_MAX,mid =0;
        while(start <= end){
            mid = start + (end-start)/2;
            long long totalTime = f(piles, mid);
            if(totalTime <= h){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};