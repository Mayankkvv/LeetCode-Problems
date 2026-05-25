class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> adjMat(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++) {
            adjMat[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adjMat[u][v] = wt;
            adjMat[v][u] = wt;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adjMat[i][k] == 1e8 || adjMat[k][j] == 1e8)
                        continue;

                    adjMat[i][j] =
                        min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }

        int ans = INT_MAX;
        int city = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (adjMat[i][j] <= d)
                    cnt++;
            }
            if (cnt <= ans) {
                ans = cnt;
                city = i;
            }
        }

        return city;
    }
};