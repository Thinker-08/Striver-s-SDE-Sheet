vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(!s.empty() or temp!=NULL)
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            temp=temp->right;
        }
        return ans;
    }