void find(TreeNode<int> *root,int x,TreeNode<int>*&ans)
{
    if(root==NULL)
        return;
    if(root->val>x)
        find(root->left,x,ans);
    else
    {
        ans=root;
        find(root->right,x,ans);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    TreeNode<int>* ans=root;
    find(root,X,ans);
    return ans->val;
}