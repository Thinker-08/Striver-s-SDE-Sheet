vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    while(root!=NULL)
    {
        if(root->left!=NULL)
        {
            TreeNode* temp = root;
            ans.push_back(root->data);
            TreeNode* temp2 = root->right;
            root=root->left;
            while(root->right!=NULL)
                root=root->right;
            root->right = temp2;
            temp->right=NULL;
            temp->right = temp->left;
            temp->left = NULL;
            root = temp->right;
        }
        else
        {
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}
