bool check(vector<int> &v,int index,int sum,vector<vector<int>> &dp)
    {
        if(index>=v.size() or sum<0 )
            return false;
        if(sum==0)
            return true;
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        dp[index][sum] = check(v,index+1,sum-v[index],dp) or check(v,index+1,sum,dp);
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
            return false;
        else
        {
            int const N=1e5;
            vector<vector<int>> dp(nums.size(),vector<int>(N,-1));
            return (check(nums,0,sum/2,dp));
        }
    }