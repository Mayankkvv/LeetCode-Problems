class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> adj[n];
        for(int i =0; i < n; i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            vector<int> vec;
            vec = q.front();
            q.pop();
            int node = vec.back();
            if(node == n -1){
                ans.push_back(vec);
            }else{
                for(auto it:adj[node]){
                    vec.push_back(it);
                    q.push(vec);
                    vec.pop_back();
                }
            }
        }
        return ans;
    }
};