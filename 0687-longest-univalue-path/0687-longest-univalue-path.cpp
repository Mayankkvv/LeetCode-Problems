/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int left = dfs(node -> left);
        int right = dfs(node -> right);

        int leftpath = 0, rightpath = 0;
        if(node -> left && node -> left -> val == node -> val){
            leftpath = left + 1;
        }
        if(node -> right && node -> right -> val == node -> val){
            rightpath = right + 1;
        }
        ans = max(ans , leftpath + rightpath);
        return max(leftpath , rightpath);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};