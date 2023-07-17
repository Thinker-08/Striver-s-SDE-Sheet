vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                TreeNode* temp = root;
                TreeNode* temp2 = root->left;
                root=root->left;
                while(root->right!=NULL)
                    root=root->right;
                root->right = temp;
                temp->left=NULL;
                root = temp2;
            }
            else
            {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
