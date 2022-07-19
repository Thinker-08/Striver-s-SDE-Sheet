TreeNode* build(vector<int> &nums,int l,int r)
    {
        if(l>r)
            return NULL;
        if(l==r)
            return new TreeNode(nums[l]);
        int mid=(l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=build(nums,l,mid-1);
        root->right=build(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return (build(nums,0,nums.size()-1));
    }