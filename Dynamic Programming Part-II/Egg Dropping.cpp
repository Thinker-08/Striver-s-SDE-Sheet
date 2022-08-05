//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
          int egg[n+1][k+1];
        for(int i=1;i<=n;i++)
        {
            egg[i][1] = 1;
            egg[i][0] = 0;
        }
        for(int i=1;i<=k;i++)
        {
            egg[1][i] = i;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                egg[i][j] = INT_MAX;
                for(int x=1;x<=j;x++)
                {
                    int r = 1+max(egg[i-1][x-1], egg[i][j-x]);
                    if(r<egg[i][j])
                    egg[i][j] = r;
                }
            }
        }
        return egg[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends