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
    int sum=0,maxi=INT_MIN;
    rep(i,0,n)
    {
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0)
            sum=0;
    }
    cout<<maxi;
    newline;
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
