void depth(TreeNode* head,int &height)
    {
        if(head==NULL)
        {
            height=0;
            return;
        }
        int l=0,r=0;
        depth(head->left,l);
        depth(head->right,r);
        height=max(l,r)+1;
    }
    int maxDepth(TreeNode* root)
    {
        int ans=0;
        depth(root,ans);
        return ans;
    }