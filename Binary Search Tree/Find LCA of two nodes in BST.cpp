TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p or root==q)
            return root;
        TreeNode* lfind = lowestCommonAncestor(root->left,p,q);
        TreeNode* rfind = lowestCommonAncestor(root->right,p,q);
        if(lfind==NULL and rfind==NULL)
            return NULL;
        if(lfind!=NULL and rfind!=NULL)
            return root;
        if(lfind==NULL and rfind!=NULL)
            return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }