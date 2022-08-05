//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        vector<vector<int>> dp(str.length(),vector<int>(str.length()));
        for(int i=0;i<str.length();i++)
        {
            for(int j=0,k=i;k<str.length();j++,k++)
            {
                if(k==j)
                    dp[j][k]=1;
                else
                {
                    if(abs(k-j)==1)
                    {
                        if(str[k]==str[j])
                            dp[j][k]=1;
                        else
                            dp[j][k]=0;
                    }
                    else
                    {
                        if(str[k]==str[j] and dp[j+1][k-1]==1)
                            dp[j][k]=1;
                        else
                            dp[j][k]=0;
                    }
                }
            }
        }
        vector<int> par(str.length());
        for(int i=0;i<str.length();i++)
        {
            if(dp[0][i])
                par[i]=0;
            else
            {
                par[i]=INT_MAX;
                for(int j=0;j<i;j++)
                {
                    if(dp[j+1][i] and 1+par[j]<par[i])
                        par[i]=1+par[j];
                }
            }
        }
        return par[str.length()-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends