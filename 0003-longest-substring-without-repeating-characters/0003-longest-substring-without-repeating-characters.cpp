class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l =0, r = 0, maxlen = 0;
        //st.insert(s[l]);
        int n = s.size();
        while(r < n){
            st.insert(s[r]);
            if(st.size() == r - l + 1){
                maxlen = max(maxlen, r-l+1);
                r++;
            }
            else if(st.size() < r - l + 1){
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};