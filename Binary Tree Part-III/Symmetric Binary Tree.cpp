bool check(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL and root2==NULL)
            return true;
        if(root1!=NULL and root2!=NULL and root1->val==root2->val)
            if(check(root1->left,root2->right) and check(root1->right,root2->left))
                return true;
        return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(check(root,root))
            return true;
        else
            return false;
    }