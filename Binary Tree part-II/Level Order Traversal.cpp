vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL)
            return {};
        while(!q.empty())
        {
            int count=q.size();
            vector<int> x;
            while(count--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                { 
                    q.push(temp->right);
                }
                x.push_back(temp->val);
            }
            if(!x.empty())
                ans.push_back(x);
        }
        return ans;
    }