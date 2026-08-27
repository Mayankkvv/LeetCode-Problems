class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = INT_MIN;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1:st.top();
                maxArea = max(maxArea, (nse - pse - 1)*heights[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1)*heights[element]);
        }
        return maxArea;   //TC > O(N) + O(N)
    }
};