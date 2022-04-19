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
    int target;cin>>target;
    vector<int> pref(n);
    pref[0]=v[0];
    rep(i,1,n)
        pref[i]=pref[i-1]^v[i];
    int ans=0;map<int,int> mp;
    rep(i,0,n)
    {
        int temp=pref[i]^target;
        ans+=mp[temp];
        if(pref[i]==target)
            ans++;
        mp[pref[i]]++;
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

