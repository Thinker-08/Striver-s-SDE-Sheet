int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            cout<<dp[i]<<" ";
            ans=max(ans,dp[i]);
        }
        return ans+1;
    }