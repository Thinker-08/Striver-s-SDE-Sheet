TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left==NULL and right!=NULL)
            return right;
        if(right==NULL and left!=NULL)
            return left;
        if(right!=NULL and left!=NULL)
            return root;
        return NULL;
    }
