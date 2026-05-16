class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Build graph
        for (int i = 0; i < prerequisites.size(); i++) {

            adj[prerequisites[i][1]]
                .push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses, 0);
        // Calculate indegree
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;

        // Push indegree 0 nodes
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {

                q.push(i);
            }
        }

        vector<int> topo;
        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (topo.size() == numCourses) {

            return topo;
        }

        return {};
    }
};
