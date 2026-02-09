class Solution {
    bool f(vector<vector<char>>& board, string& word, int i, int j, int w, vector<vector<int>>& arr) {
        if (w == (int)word.size()) return true;

        if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size()) return false;

        if (arr[i][j] == 0) return false;              // ✅ can't reuse cell
        if (board[i][j] != word[w]) return false;      // ✅ must match

        arr[i][j] = 0; // mark visited

        bool ok = f(board, word, i + 1, j, w + 1, arr) ||
                  f(board, word, i - 1, j, w + 1, arr) ||
                  f(board, word, i, j + 1, w + 1, arr) ||
                  f(board, word, i, j - 1, w + 1, arr);

        arr[i][j] = 1; // ✅ unmark (backtrack)

        return ok;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> arr(n, vector<int>(m, 1)); // ✅ fresh for each start
                if (f(board, word, i, j, 0, arr)) return true;
            }
        }
        return false;
    }
};
