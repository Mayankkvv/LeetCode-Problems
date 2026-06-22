/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void makeParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        if(cur -> left){
            parent[cur -> left] = cur;
            q.push(cur -> left);
        }
        if(cur -> right){
            parent[cur -> right] = cur;
            q.push(cur -> right);
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root , parent);

        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;
        int cur_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(cur_level++ == k) break;
            for(int i =0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> left && !vis[cur->left]){
                    vis[cur -> left] = true;
                    q.push(cur -> left);
                }
                if(cur -> right && !vis[cur -> right]){
                    vis[cur-> right] = true;
                    q.push(cur -> right);
                }
                if(parent[cur] && !vis[parent[cur]]){
                    vis[parent[cur]] = true;
                    q.push(parent[cur]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node -> val);
        } 
        return ans;

    }
};