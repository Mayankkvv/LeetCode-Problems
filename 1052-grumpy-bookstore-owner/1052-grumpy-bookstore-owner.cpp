
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
        }
        int l = 0, r = minutes - 1;
        int sum = 0, maxi = 0;
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                sum += customers[i];
            }
        }
        maxi = sum;
        while(r + 1 < customers.size()){
            r++;
            if(grumpy[r] == 1){
                sum += customers[r];
            }
            if(grumpy[l] == 1){
                sum -= customers[l];
            }
            l++;
            maxi = max(maxi, sum);
        }
        return ans + maxi;
    }
};
