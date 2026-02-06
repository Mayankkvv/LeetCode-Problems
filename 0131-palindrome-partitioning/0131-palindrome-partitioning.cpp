class Solution {
private:
    void f(int index, vector<vector<string>>& ans, vector<string>& temp, string& s){
        if(index == s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s , index, i)){
                temp.push_back(s.substr(index, i-index +1));
                f(i+1, ans, temp, s);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0, ans , temp, s);
        return ans;
    }
};