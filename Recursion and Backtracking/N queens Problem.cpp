#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<vector<char>>> ans;
bool isSafe(int a,int b,vector<vector<int>> &mat)
{
    if(mat[a][b])
        return false;
    return true;
}
vector<vector<int>> make(int a,int b,vector<vector<int>> mat)
{
    mat[a][b]=1;
    for(int i=a,j=b;i<mat.size();i++)
        mat[i][j]=1;
    for(int j=b,i=a;j<mat.size();j++)
        mat[i][j]=1;
    for(int i=a,j=b;i>=0;i--)
        mat[i][j]=1;
    for(int j=b,i=a;j>=0;j--)
        mat[i][j]=1;
    for(int i=a,j=b;i<mat.size() and j<mat.size();i++,j++)
        mat[i][j]=1;
    for(int i=a,j=b;i<mat.size() and j>=0;i++,j--)
        mat[i][j]=1;
    for(int i=a,j=b;i>=0 and j<mat.size();i--,j++)
        mat[i][j]=1;
    for(int i=a,j=b;i>=0 and j>=0;i--,j--)
        mat[i][j]=1;
    return mat;
}
void driver(vector<vector<char>> temp,vector<vector<int>> mat,int idx)
{
    if(idx>=mat.size())
    {ans.push_back(temp);return;}
    for(int i=0;i<mat.size();i++)
    {
        if(isSafe(idx,i,mat))
        {
            temp[idx][i]='Q';
            vector<vector<int>> new_mat=make(idx,i,mat);
            driver(temp,new_mat,idx+1);
            temp[idx][i]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> temp(n,vector<char>(n,'.'));
    vector<vector<int>> mat(n,vector<int> (n,0));
    driver(temp,mat,0);
    vector<vector<string>> ret;
    for(int i=0;i<ans.size();i++)
    {
        vector<string> ll;
        for(int j=0;j<ans[i].size();j++)
        {
            string ss;
            for(int k=0;k<ans[i][j].size();k++)
                ss+=ans[i][j][k];
            ll.push_back(ss);   
        }
        ret.push_back(ll);
    }
    return ret;
}
int32_t main()
{
    string s;
    int t,n;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<string>> x=solveNQueens(n);
        rep(i,0,x.size())
        {
            rep(j,0,x[i].size())
                cout<<x[i][j]<<endl;
            newline;
        }
    }
}


