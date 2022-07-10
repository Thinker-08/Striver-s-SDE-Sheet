/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> a;
 void path(TreeNode* root,int temp,vector<int> &ans)
 {
    if(root==NULL)
        return;
    if(root->val==temp)
    {
        ans.push_back(temp);
        a=ans;
        return;
    }
    ans.push_back(root->val);
    path(root->left,temp,ans);
    path(root->right,temp,ans);
    ans.pop_back();
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> temp;
    path(A,B,temp);
    return a;
}
