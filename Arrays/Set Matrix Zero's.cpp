#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
const int N=1e5+10;
void tests()
{
    unordered_map<int,int> rows,cols;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m));
    rep(i,0,n)
        rep(j,0,m)
            cin>>mat[i][j];
    rep(i,0,n)
        rep(j,0,m)
            if(mat[i][j]==0)
                rows[i]=1,cols[j]=1;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(rows[i])
                mat[i][j]=0;
            if(cols[j])
                mat[i][j]=0;
        }
    }
    rep(i,0,n)
    {
        rep(j,0,m)
            cout<<mat[i][j]<<" ";
        newline;
    }
}
int32_t main()
{
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        tests();
        newline;
    }
}
