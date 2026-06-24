class Codec {
public:

    // Serialize
    string serialize(TreeNode* root) {

        if(root == NULL) return "";

        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if(cur == NULL) {
                s += "#,";
            }
            else {

                s += to_string(cur->val) + ",";

                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s;
    }

    // Deserialize
    TreeNode* deserialize(string data) {

        if(data.size() == 0) return NULL;

        stringstream ss(data);

        string str;

        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Left Child
            getline(ss, str, ',');

            if(str != "#") {

                TreeNode* leftNode = new TreeNode(stoi(str));

                node->left = leftNode;

                q.push(leftNode);
            }

            // Right Child
            getline(ss, str, ',');

            if(str != "#") {

                TreeNode* rightNode = new TreeNode(stoi(str));

                node->right = rightNode;

                q.push(rightNode);
            }
        }

        return root;
    }
};