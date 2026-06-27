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
    void traverse(TreeNode* node,vector<int> &inorder)
    {
        if(node==NULL)  return ;
        traverse(node->left,inorder);
        inorder.push_back(node->val);
        traverse(node->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traverse(root,inorder);
        int p1=0,p2=inorder.size()-1;
        while(p1<p2)
        {
            if(inorder[p1]+inorder[p2]==k)  return true;
            else if(inorder[p1]+inorder[p2]<k)  p1++;
            else    p2--;
        }
        return false;
    }
};