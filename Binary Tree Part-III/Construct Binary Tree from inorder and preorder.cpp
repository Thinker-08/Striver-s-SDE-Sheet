    TreeNode* build(vector<int> &preorder,vector<int> &inorder,int &idx,int left,int right)
    {
        if(left>right)
            return NULL;
        int ver=left;
        while(preorder[idx]!=inorder[ver])
            ver++;
        TreeNode* node=new TreeNode(preorder[idx]);
        idx++;
        node->left=build(preorder,inorder,idx,left,ver-1);
        node->right=build(preorder,inorder,idx,ver+1,right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return (build(preorder,inorder,idx,0,inorder.size()-1));
    }