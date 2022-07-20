int const N=-1*(1e5);
    map<int,int> mp;
    void convert(TreeNode* root)
    {
        if(root==NULL)
            return;
        convert(root->left);
        mp[root->val]=N;
        convert(root->right);
    }
    bool check(TreeNode* root,int sum)
    {
        if(root==NULL)
            return false;
        if(mp[root->val]+root->val==sum)
            return true;
        mp[sum-root->val]=(root->val);
        if(check(root->left,sum) or check(root->right,sum))
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        convert(root);
        return (check(root,k));
    }