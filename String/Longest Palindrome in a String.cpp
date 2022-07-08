// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(abs(a.first-a.second)==abs(b.first-b.second))
        {
            return a.second<b.second;
        }
        return abs(a.first-a.second)>abs(b.first-b.second);
    }
    string longestPalin (string S) {
        int dp[S.length()][S.length()];
        for(int i=0;i<S.length();i++)
        {
            for(int j=0;j<S.length();j++)
            {
                if(i>j)
                    dp[i][j]=0;
            }
        }
        for(int k=0;k<S.length();k++)
        {
            for(int i=0,j=k;i<S.length()-k;i++,j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else
                {
                    if((j-i)==1)
                    {
                        if(S[i]==S[j])
                            dp[i][j]=1;
                        else
                            dp[i][j]=0;
                    }
                    else
                    {
                        if(S[i]==S[j] && dp[i+1][j-1]==1)
                            dp[i][j]=1;
                        else
                            dp[i][j]=0;
                    }
                }

            }
        }
        int start=0,end=0;
        pair<int,int> p;
        p.first=0;p.second=0;
        for(int i=0;i<S.length();i++)
        {
            for(int j=i;j<S.length();j++)
            {
                if(dp[i][j]==1)
                    end=j;
            }
            if(abs(i-end)>abs(p.first-p.second))
            {
                p.first=i;
                p.second=end;
            }
        }
        string ans;
        for(int i=p.first;i<=p.second;i++)
            ans=ans+S[i];
        return ans;
    }
};
// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends