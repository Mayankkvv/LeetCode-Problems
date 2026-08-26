class Solution {
private:
    vector<int> findNse(vector<int>& arr){
        stack<int> st;
        vector<int> nse(arr.size(), 0);
        for(int i = arr.size() - 1; i>= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                 st.pop();   
            }
            if(st.empty()) nse[i] = arr.size();
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPsee(vector<int>& arr){
        vector<int> psee(arr.size(), 0);
        stack<int> st;
        for(int i = 0;i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) psee[i] = -1;
            else psee[i] = st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        long long mod = (int)(1e9 + 7);
        vector<int> nse = findNse(arr);
        vector<int> psee = findPsee(arr);
        for(int i = 0; i < arr.size(); i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (left * right * arr[i])%mod)%mod;
        }
        return total;
    }
};