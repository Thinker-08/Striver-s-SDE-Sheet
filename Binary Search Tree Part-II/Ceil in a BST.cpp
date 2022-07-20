void find(BinaryTreeNode<int> *root,int x,BinaryTreeNode<int>*&ans)
{
    if(root==NULL)
        return;
    if(root->data<x)
        find(root->right,x,ans);
    else
    {
        ans=root;
        find(root->left,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *root, int x){
    BinaryTreeNode<int>* ans=new BinaryTreeNode<int>(-1);
    find(root,x,ans);
    return ans->data;
}