class Solution {
private:
    int f(vector<int>& bloomDay, int mid, int m , int k){
        int cnt = 0, noOfBookies = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }else{
                noOfBookies += cnt / k;
                cnt = 0;
            }
        }
        noOfBookies += cnt / k;
        return noOfBookies;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(f(bloomDay, mid, m, k) >= m){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }
};