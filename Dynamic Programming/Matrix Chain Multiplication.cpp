// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        for(int i=0;i<N;i++)
            dp[i][i]=0;
        for(int l=2;l<=N-1;l++)
        {
            for(int i=1;i<=N-l;i++)
            {
                int j=i+l-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                        dp[i][j]=min(dp[i][j],temp);
                }
            }
        }
        return dp[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends