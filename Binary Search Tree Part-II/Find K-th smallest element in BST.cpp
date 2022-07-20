vector<int> ans;
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        preorder(root->left);
        ans.push_back(root->val);
        preorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        preorder(root);
        return ans[k-1];
    }