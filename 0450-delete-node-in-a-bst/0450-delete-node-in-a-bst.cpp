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
private:
    TreeNode* findLast(TreeNode* root){
        if(root -> right == NULL){
            return root;
        }
        return findLast(root -> right);
    }
    TreeNode* f(TreeNode* root){
        if(root -> left == NULL){
            return root -> right;
        }
        else if(root -> right == NULL){
            return root -> left;
        }
        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLast(root -> left);
        lastRight -> right = rightChild;
        return root -> left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        if(root == NULL) return NULL;
        if(root -> val == key) return f(root);
        while(cur){
            if(cur -> val > key){
                if(cur -> left != NULL && cur -> left -> val == key){
                    cur -> left = f(cur -> left);
                    break;
                }else{
                    cur = cur -> left;
                }
            }
            else{
                if(cur -> right != NULL && cur -> right -> val == key){
                    cur -> right = f(cur -> right);
                    break;
                }else{
                    cur = cur -> right;
                }
            }
        }
        return root;
    }
};