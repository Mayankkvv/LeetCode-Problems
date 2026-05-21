class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // blocked start or end
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {

            return -1;
        }

        // single cell
        if (n == 1 && m == 1) {

            return 1;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});

        dist[0][0] = 1;

        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {

            auto it = q.front();

            q.pop();

            int dis = it.first;

            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {

                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {

                    if (nrow == n - 1 && ncol == m - 1) {

                        return dis + 1;
                    }

                    dist[nrow][ncol] = dis + 1;

                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};