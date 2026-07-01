class Solution {
public:
    typedef long long ll;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> vis(n,0);
        //{num , index}
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i] , i});
        }
        ll sum = 0;
        while(pq.size()!= 0){
            int num = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(vis[ind] == 0){
                vis[ind] = 1;
                sum += num;
                if(ind - 1 >= 0 && vis[ind-1] == 0){
                    vis[ind - 1] = 1;
                }
                if(ind + 1 < n && vis[ind+1] == 0){
                    vis[ind + 1] = 1;
                }
            }
        }
        return sum;
    }
};