class Solution {
private:

    void dfs(int row, int col,
             vector<vector<char>>& board,
             vector<vector<int>>& vis,
             int delrow[],
             int delcol[]) {

        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board, vis, delrow, delcol);
            }
        }
    }

public:

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Top and Bottom rows
        for (int j = 0; j < m; j++) {

            if (board[0][j] == 'O' && !vis[0][j]) {

                dfs(0, j, board, vis, delrow, delcol);
            }

            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {

                dfs(n - 1, j, board, vis, delrow, delcol);
            }
        }

        // Left and Right columns
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O' && !vis[i][0]) {

                dfs(i, 0, board, vis, delrow, delcol);
            }

            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {

                dfs(i, m - 1, board, vis, delrow, delcol);
            }
        }

        // Convert remaining O to X
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && board[i][j] == 'O') {

                    board[i][j] = 'X';
                }
            }
        }
    }
};