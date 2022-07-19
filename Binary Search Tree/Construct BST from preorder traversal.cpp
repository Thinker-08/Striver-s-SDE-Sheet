TreeNode* build(vector<int> &preorder,int& idx,int mini,int maxi)
    {
        if(idx>=preorder.size() or preorder[idx]<mini or preorder[idx]>maxi)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build(preorder,idx,mini,root->val);
        root->right = build(preorder,idx,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return (build(preorder,idx,INT_MIN,INT_MAX));
    }