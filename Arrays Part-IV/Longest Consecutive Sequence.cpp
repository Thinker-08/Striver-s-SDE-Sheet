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
    int n,ans=0;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    unordered_set<int> s;
    rep(i,0,n)
        s.insert(v[i]);
    rep(i,0,n)
    {
        if(s.find(v[i]-1)==s.end())
        {
            int temp=v[i];
            while(s.find(temp)!=s.end())
                temp++;
            ans=max(ans,temp-v[i]);
        }
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

