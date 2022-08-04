int coinChange(vector<int>& coins, int amount)
    {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<coins.size()+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                    dp[i][j]=1e9;
                else if(j==0)
                    dp[i][j]=0;
                else
                {
                    if(coins[i-1]>j)
                        dp[i][j]=dp[i-1][j];
                    else
                    {
                        dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                    }
                }
            }
        }
        return dp[coins.size()][amount]>=1e9?-1:dp[coins.size()][amount];
    }