class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<pair<int,int>> adj[n];

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        if (0 < disappear[0]) {
            dist[0] = 0;
            pq.push({0,0});
        }

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            if (time > dist[node])
                continue;

            for (auto &nbr : adj[node]) {

                int adjNode = nbr.first;
                int wt = nbr.second;

                int newTime = time + wt;

                if (newTime < disappear[adjNode] &&
                    newTime < dist[adjNode]) {

                    dist[adjNode] = newTime;
                    pq.push({newTime, adjNode});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};