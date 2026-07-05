class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int maxNum=num;
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                maxNum=max(maxNum,stoi(s));
                swap(s[i],s[j]);
            }
        }
        return maxNum;
    }
};