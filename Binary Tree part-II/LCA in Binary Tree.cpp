bool find(TreeNode* root,TreeNode* temp)
    {
        if(root==NULL)
            return false;
        if(root==temp)
            return true;
        else
        {
            if((find(root->left,temp)) or (find(root->right,temp)))
                return true;
            else
                return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p or root==q)
            return root;
        bool lroot = (find(root->left,p)) or (find(root->left,q));
        bool rroot = (find(root->right,q) or find(root->right,p));
        if(lroot and rroot)
            return root;
        if(lroot==false and rroot)
            return lowestCommonAncestor(root->right,p,q);
        if(lroot and rroot==false)
            return lowestCommonAncestor(root->left,p,q);
        return NULL;
    }