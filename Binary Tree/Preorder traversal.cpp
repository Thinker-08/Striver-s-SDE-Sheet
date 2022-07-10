vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> s;
        while(!s.empty() or root!=NULL)
        {
            while(root!=NULL)
            {
                s.push(root);
                ans.push_back(root->val);
                root=root->left;
            }
            root=s.top();
            s.pop();
            root=root->right;
        }
        return ans;
    }