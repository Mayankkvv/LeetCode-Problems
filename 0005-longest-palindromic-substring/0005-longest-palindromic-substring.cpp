class Solution {
private:
    bool check(string& s, int i, int j){
        if(i >= j) return true;
        if(s[i] == s[j]) return check(s, i + 1, j -1);
        return false;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int sp = 0;
        int maxLen = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(s,i,j)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};