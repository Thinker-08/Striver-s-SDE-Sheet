vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<int> fin;
        queue<TreeNode*> q;
        if(root==NULL)
            return {};
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                fin.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            else
            {
                ans.push_back(fin);
                if(q.empty())
                {
                    break;
                }
                else
                {
                    q.push(NULL);
                    fin.clear();
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(i%2)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }