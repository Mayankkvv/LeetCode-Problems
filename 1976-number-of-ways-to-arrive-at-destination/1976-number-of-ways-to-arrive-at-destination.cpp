class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int, int>> adj[n];

        // Build graph
        for (auto it : roads) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int mod = 1e9 + 7;

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        vector<long long> dist(n, 1e18);

        vector<int> ways(n, 0);

        dist[0] = 0;

        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long dis = pq.top().first;
            long long node = pq.top().second;

            pq.pop();

            for (auto it : adj[node]) {

                long long adjNode = it.first;
                long long edgeW = it.second;

                // shorter path found
                if (dis + edgeW < dist[adjNode]) {

                    dist[adjNode] = dis + edgeW;

                    pq.push({dist[adjNode], adjNode});

                    ways[adjNode] = ways[node];
                }

                // another shortest path
                else if (dis + edgeW == dist[adjNode]) {

                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};