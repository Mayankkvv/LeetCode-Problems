class Solution {
private:
    int FindMaxInCol(vector<vector<int>>& mat, int col, int n){
        int maxi = INT_MIN, index = -1;
        for(int i = 0; i < n; i++){
            if(maxi < mat[i][col]){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int start = 0, end = m - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int MaxRow = FindMaxInCol(mat, mid, n);
            int left = mid - 1 >= 0 ? mat[MaxRow][mid-1] : -1;
            int right = mid + 1 < m ? mat[MaxRow][mid+1] : -1;
            if(mat[MaxRow][mid] > left && mat[MaxRow][mid] > right){
                return {MaxRow, mid};
            }
            else if(mat[MaxRow][mid] < left){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return {-1,-1};
    }
};