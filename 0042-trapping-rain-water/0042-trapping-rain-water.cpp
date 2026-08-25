class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, lmax = 0, rmax = 0, tot = 0;
        int r = n - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    tot += lmax - height[l];
                }else{
                    lmax = height[l];
                }
                l++;
            }else{
                if(rmax > height[r]){
                    tot += rmax - height[r];
                }else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return tot;
    }
};