class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                queue<int>q;
                q.push(i);

                 while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(auto &neigh:graph[node])
                    {
                        if(color[neigh]==-1)
                        {
                            if(color[node]) color[neigh]=0;
                            else color[neigh]=1;
                            q.push(neigh);
                        }
                        else if(color[neigh]!=color[node]) continue;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};