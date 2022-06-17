// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int a[],int n,int m,int test)
    {
        int temp=1,sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>test)
                return false;
            if(sum+a[i]>test)
            {
                temp++;
                sum=a[i];
                if(temp>m)
                    return false;
            }
            else
                sum+=a[i];
        }
    }
    int findPages(int A[], int N, int M) 
    {
        int hi=accumulate(A,A+N,0);
        int lo=0;
        while(hi-lo>1)
        {
            int mid=(hi+lo)/2;
            if(check(A,N,M,mid))
                hi=mid;
            else
                lo=mid;
        }
        if(check(A,N,M,lo))
            return lo;
        else
        {
            if(check(A,N,M,hi))
                return hi;
            else
                return -1;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends