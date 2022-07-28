vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        if(root==NULL)
            return {};
        s1.push(root);
        while(!s1.empty())
        {
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left)
                s1.push(root->left);
            if(root->right)
                s1.push(root->right);
        }
        vector<int> ans;
        while(!s2.empty())
            ans.push_back(s2.top()->val),s2.pop();
        return ans;
    }
    