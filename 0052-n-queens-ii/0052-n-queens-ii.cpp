class Solution {
public:
    void f(int col, int &cnt, vector<string>& board, vector<int>& lr, vector<int>& ud, vector<int>& ld, int n){
        if(col == n){
            cnt++;
            return;
        }
        for(int row = 0; row < n; row++){
            if(lr[row] == 0 && ld[row + col] == 0 && ud[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                lr[row] = 1;
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;

                f(col + 1, cnt, board, lr, ud, ld, n);

                board[row][col] = '.';
                lr[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<int> lr(n, 0);
        vector<int> ud(2*n - 1, 0);
        vector<int> ld(2*n - 1, 0);

        f(0, cnt, board, lr, ud, ld, n);
        return cnt;
    }
};
