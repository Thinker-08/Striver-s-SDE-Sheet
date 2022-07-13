bool depth(TreeNode* head,int &height)
    {
        if(head==NULL)
        {
            height=0;
            return true;
        }
        int l=0,r=0;
        if(depth(head->left,l) and depth(head->right,r) and abs(l-r)<=1)
        {
            height=max(l,r)+1;
            return true;
        }
        else
        {
            height=max(l,r)+1;
            return false;
        }

    }
    bool isBalanced(TreeNode* root) {
        int ans=0;
        return (depth(root,ans));
    }