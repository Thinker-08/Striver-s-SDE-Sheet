TreeNode* build(vector<int> &postorder,vector<int> &inorder,int& idx,int left,int right)
    {
        if(left>right)
            return NULL;
        int ver=left;
        while(postorder[idx]!=inorder[ver])
            ver++;
        idx--;
        TreeNode* node = new TreeNode(inorder[ver]);
        node->right = build(postorder,inorder,idx,ver+1,right);
        node->left = build(postorder,inorder,idx,left,ver-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int idx=postorder.size()-1;
        return (build(postorder,inorder,idx,0,inorder.size()-1));
    }