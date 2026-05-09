class Solution {
public:

    int dfs(TreeNode* node, long long targetSum) {

        if(node == NULL) return 0;

        int count = 0;

        if(node->val == targetSum)
            count++;

        count += dfs(node->left, targetSum - node->val);
        count += dfs(node->right, targetSum - node->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return 0;

        return dfs(root, targetSum)
             + pathSum(root->left, targetSum)
             + pathSum(root->right, targetSum);
    }
};