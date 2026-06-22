class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            long long first = 0, last = 0;
            for(int i = 0; i < size; i++) {
                long long cur = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = cur;
                if(i == size - 1) last = cur;

                if(node->left) {
                    q.push({node->left, 2 * cur + 1});
                }

                if(node->right) {
                    q.push({node->right, 2 * cur + 2});
                }
            }
            width = max(width, last - first + 1);
        }
        return (int)width;
    }
};