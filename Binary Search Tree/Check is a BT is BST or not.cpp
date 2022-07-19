const long long N=3*(1e9);
    bool valid(TreeNode* root,long long l,long long r)
    {
        if(root==NULL)
            return true;
        if(root->val>l and root->val<r)
        {
            if(valid(root->left,l,root->val) and valid(root->right,root->val,r))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root)
    {
        if(valid(root,-N,N))
            return true;
        else
            return false;
    }