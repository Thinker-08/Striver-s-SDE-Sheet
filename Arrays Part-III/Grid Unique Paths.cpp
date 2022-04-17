#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int uniquePaths(int m, int n) {
    vector<vector<int>> paths(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0)
                paths[i][j]=1;
            else if(i==0)
                paths[i][j]=paths[i][j-1];
            else if(j==0)
                paths[i][j]=paths[i-1][j];
            else
            {
                paths[i][j]=paths[i-1][j]+paths[i][j-1];
            }
        }
    }
    return paths[m-1][n-1];
}
void tests()
{
    int m,n;
    cin>>m>>n;
    int ans=uniquePaths(m,n);
    cout<<ans;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

