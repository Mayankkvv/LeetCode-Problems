class Solution {
public:
    
    TreeNode* helper(TreeNode* root){
        
        // no left child
        if(root->left == nullptr){
            return root->right;
        }

        // no right child
        if(root->right == nullptr){
            return root->left;
        }

        // both children exist
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = root->left;

        while(lastRight->right){
            lastRight = lastRight->right;
        }

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr) return nullptr;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* cur = root;
        while(cur){
            if(key < cur->val){
                if(cur->left && cur->left->val == key){
                    cur->left = helper(cur->left);
                    break;
                }
                cur = cur->left;
            }
            else{
                if(cur->right && cur->right->val == key){
                    cur->right = helper(cur->right);
                    break;
                }
                cur = cur->right;
            }
        }
        return root;
    }
};