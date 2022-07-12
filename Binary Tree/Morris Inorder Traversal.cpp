vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root!=NULL)
        {
            if(root->left==NULL)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode* prev=root->left;
                while(prev->right!=NULL and prev->right!=root)
                    prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=root;
                    root=root->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;
    }