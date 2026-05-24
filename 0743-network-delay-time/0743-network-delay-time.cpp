class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        vector<pair<int, int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //dist, node
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto it: adj[node]){
                int edgeW = it.second;
                int adjNode = it.first;
                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    pq.push({dis + edgeW, adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i< n+1; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};