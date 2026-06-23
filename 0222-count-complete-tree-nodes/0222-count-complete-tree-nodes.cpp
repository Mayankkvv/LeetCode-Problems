class Solution {
private:

    int findHeightL(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }

    int findHeightR(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }

public:

    int countNodes(TreeNode* root) {

        if(root == NULL)
            return 0;
                                       // TC -> O((logN)^2
                                       // SC -> O(LOGN)
        int lh = findHeightL(root);
        int rh = findHeightR(root);

        // Perfect Binary Tree
        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};