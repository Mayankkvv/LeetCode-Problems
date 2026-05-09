class Solution {
private:

    int helper(TreeNode* node, int& tiltSum) {

        if(node == NULL) return 0;

        int leftSum = helper(node->left, tiltSum);
        int rightSum = helper(node->right, tiltSum);

        tiltSum += abs(leftSum - rightSum);

        return leftSum + rightSum + node->val;
    }

public:
    int findTilt(TreeNode* root) {

        int tiltSum = 0;

        helper(root, tiltSum);

        return tiltSum;
    }
};