class Solution {
private:
    int allocateWeights(vector<int>& array, int mid) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < array.size(); i++) {
            if (sum + array[i] > mid) {
                cnt++;
                sum = array[i];
            }
            else {
                sum += array[i];
            }
        }
        return cnt;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = 0, mid = 0;
        int ans = 0;
        for(int i = 0; i < weights.size(); i++){
            end += weights[i];
        }
        while(start <= end){
            mid = start + (end - start)/2;
            if(allocateWeights(weights, mid) <= days){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};