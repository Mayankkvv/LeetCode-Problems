class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int a[26] = {0};
        int b[26] = {0};
        for(int i =0; i < goal.size(); i++){
            b[goal[i] - 'a'] = 1;
        }
        for(int i =0; i < s.size(); i++){
            a[s[i] - 'a'] = 1;
        }
        for(int i = 0; i < 26; i++){
            if(b[i] != a[i]) return false;
        }
        return true;
    }
};