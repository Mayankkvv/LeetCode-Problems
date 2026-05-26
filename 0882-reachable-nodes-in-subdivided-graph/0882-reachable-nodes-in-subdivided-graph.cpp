class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &x : edges) {
            int a = x[0], b = x[1], w = x[2];
            adj[a].push_back({b, w + 1});
            adj[b].push_back({a, w + 1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto& [x, w] : adj[node]) {
                int newDist = d + w;
                if (newDist < dist[x]) {
                    dist[x] = newDist;
                    pq.push({newDist, x});
                }
            }
        }

        int ans = 0;
        for (auto &x : dist) {
            if (x <= maxMoves) ans += 1;
        }

        for (auto &x : edges) {
            int a = x[0], b = x[1], w = x[2];
            int reachableFromA = max(0, maxMoves - dist[a]);
            int reachableFromB = max(0, maxMoves - dist[b]);
            ans += min(w, reachableFromA + reachableFromB);
        }

        return ans;
    }
};