#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void tests()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    if(n==1)
        cout<<arr[0];
    else
    {
        int i=n-2;
        for(;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
                continue;
            else
                break;
        }
        if(i<0)
        {
            reverse(arr.begin(),arr.end());
            rep(i,0,n)
                cout<<arr[i]<<" ";
        }
        else
        {
            map<int,int> mp;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                    mp[arr[j]]=j;
            }
            swap(arr[(*mp.begin()).second],arr[i]);
            reverse(arr.begin()+i+1,arr.end());
            rep(i,0,n)
                cout<<arr[i]<<" ";
            newline;
        }
    }
}
int32_t main()
{
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        tests();
        newline;
    }
}
