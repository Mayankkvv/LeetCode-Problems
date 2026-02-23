class Solution {
private:
int f(vector<int>& arr, int mid, int m , int k){
    int cnt = 0, noOfBookies = 0;
    for(int i=0; i < arr.size(); i++){
        if(arr[i] <= mid){
            cnt++;
        }
        else{
            noOfBookies += cnt/k;   // changed
            cnt = 0;
        }
    }
    noOfBookies += (cnt/k);
    return noOfBookies;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX, maxi = INT_MIN, n = bloomDay.size();
        if((long long)m * k > n) return -1;   // safer, optional but recommended
        for(int i = 0; i < n; i++){
            maxi = max(bloomDay[i] , maxi);
            mini = min(bloomDay[i], mini);
        }
        int start = mini, end = maxi;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(f(bloomDay,mid, m,k) >= m){    // changed
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};