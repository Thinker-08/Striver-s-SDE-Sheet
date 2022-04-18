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
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    unordered_map<int,int> mp;
    int sum=0,ans=0;
    rep(i,0,n)
    {
        sum+=v[i];
        if(sum==0 and ans==0)
            ans=1;
        if(sum==0)
            ans=i+1;
        if(mp.find(sum)!=mp.end())
            ans=max(ans,i-mp[sum]+1);
        else 
            mp[sum]=i+1;
    }
    cout<<ans;
    newline;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

