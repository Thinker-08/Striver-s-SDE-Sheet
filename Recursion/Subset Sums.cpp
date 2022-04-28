// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void driver(vector<int> &arr,int sum,int idx)
    {
        if(idx>=arr.size())
        {
            ans.push_back(sum);
            return;
        }
        else
        {
            driver(arr,sum+arr[idx],idx+1);
            driver(arr,sum,idx+1);
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        driver(arr,0,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends