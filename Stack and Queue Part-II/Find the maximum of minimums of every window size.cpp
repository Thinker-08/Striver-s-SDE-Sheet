// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n,INT_MIN),left(n),right(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                left[i]=-1;
            }
            else
            {
                while(!s.empty() and arr[s.top()]>=arr[i])
                    s.pop();
                left[i]=s.empty()?-1:s.top();
                s.push(i);
            }
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(i);
                right[i]=n;
            }
            else
            {
                while(!s.empty() and arr[s.top()]>=arr[i])
                    s.pop();
                right[i]=s.empty()?n:s.top();
                s.push(i);
            }
        }
        for(int i=0;i<n;i++)
            ans[right[i]-left[i]-2]=max(ans[right[i]-left[i]-2],arr[i]);
        for(int i=n-2;i>=0;i--)
                ans[i]=max(ans[i],ans[i+1]);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends