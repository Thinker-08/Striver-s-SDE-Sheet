int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=grid[i][j];
                else
                {
                    if(i==0)
                    {
                        dp[i][j]=dp[i][j-1]+grid[i][j];
                    }
                    else
                    {
                        if(j==0)
                        {
                            dp[i][j]=grid[i][j]+dp[i-1][j];
                        }
                        else
                        {
                            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                        }
                    }
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }