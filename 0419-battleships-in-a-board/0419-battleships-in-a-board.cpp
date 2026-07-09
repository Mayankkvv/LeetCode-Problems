class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board,
        int n, int m){
            vis[row][col] = 1;
            int drow[4] = {-1,0,+1,0};
            int dcol[4] = {0,+1,0,-1};
            for(int i = 0; i< 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'X'
                && vis[nrow][ncol] == 0){
                    dfs(nrow, ncol, vis, board, n, m);
                }
            }
        }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    cnt++;
                    dfs(i, j, vis, board, n,m);
                }
            }
        }
        return cnt;
    }
};