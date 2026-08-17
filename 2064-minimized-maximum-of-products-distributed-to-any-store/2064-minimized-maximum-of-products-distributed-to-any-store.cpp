using ll = long long;
class Solution {
private:
    bool f(vector<int>& quantities, int mid, int n){
        ll cnt = 0;
        for(int i = 0;i <quantities.size(); i++){
            cnt += (quantities[i] + mid - 1)/mid;
        }
        if(cnt <= n) return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ll start = 1, end = 0,mid = 0;
        ll ans = 0;
        for(auto it : quantities) end += it;
        while(start <= end){
            mid = start + (end - start)/2;
            if(f(quantities, mid, n)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};