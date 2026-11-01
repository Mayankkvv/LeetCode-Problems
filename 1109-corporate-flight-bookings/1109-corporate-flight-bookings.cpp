class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2,0);
        for(int i = 0; i < bookings.size(); i++){
            int f = bookings[i][0];
            int l = bookings[i][1];
            int s = bookings[i][2];
            diff[f] += s;
            diff[l+1] -= s;
        }
        vector<int> ans(n,0); int sum = 0;
        for(int flight = 1; flight <= n; flight++){
            sum += diff[flight];
            ans[flight-1] = sum;
        }
        return ans;
    }
};