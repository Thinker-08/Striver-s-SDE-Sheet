#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<pair<int,int>> moves={
        {1,0},{-1,0},{0,1},{0,-1}
    };
int orangesRotting(vector<vector<int>>& grid)
{
  vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();
        for(int i=0;i<moves.size();i++)
        {
            if(temp.first+moves[i].first>=0 and temp.first+moves[i].first<grid.size() and
              temp.second+moves[i].second>=0 and temp.second+moves[i].second<grid[0].size() and grid[temp.first+moves[i].first][temp.second+moves[i].second]!=0 and vis[temp.first+moves[i].first][temp.second+moves[i].second]==INT_MAX)
            {
                q.push({temp.first+moves[i].first,temp.second+moves[i].second});
                vis[temp.first+moves[i].first][temp.second+moves[i].second]=vis[temp.first][temp.second]+1;
            }
        }
    }
    int time=0;
    for(int i=0;i<vis.size();i++)
    {
        for(int j=0;j<vis[i].size();j++)
        {
            if(grid[i][j]==0)
                continue;
            else if(vis[i][j]==INT_MAX)
                    return -1;
                else
                    time=max(time,vis[i][j]-1);
        }
    }
    return time;
}
void tests()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    rep(i,0,n)
        rep(j,0,m)
            cin>>v[i][j];
    int ans=orangesRotting(v);
    cout<<ans;
    newline;
}
int32_t main()
{ 
    int t;
    cin>>t;
    while(t--)
        tests();
}
