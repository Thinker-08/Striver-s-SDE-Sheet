vector<pair<int,int>> moves={
        {1,0},{0,1},{-1,0},{0,-1}
    };
    int N;
    vector<vector<int>> vis;
    void check(vector<vector<char>> &grid,int i,int j)
    {
        if(i>=grid.size() or i<0 or j>=grid[0].size() or j<0)
            return;
        if(vis[i][j] or grid[i][j]=='0')
            return;
        vis[i][j]=1;
        for(auto move:moves)
        {
            check(grid,i+move.first,j+move.second);
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    check(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    Solution(){
        N=1e3+10;
        for(int i=0;i<N;i++)
        {
            vector<int> temp;
            for(int j=0;j<N;j++)
                temp.push_back(0);
            vis.push_back(temp);
        }
    }