int find(TreeNode* root,int &height)
    {
        int lh=0,rh=0;
        if(root==NULL)
        {
            height=0;
            return 0;
        }
        int ldiameter = find(root->left,lh);
        int rdiameter = find(root->right,rh);
        height = max(lh,rh)+1;
        return max({ldiameter,rdiameter,lh+rh});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return (find(root,height));
    }