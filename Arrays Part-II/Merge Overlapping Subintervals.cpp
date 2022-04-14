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
    vector<pair<int,int>> v(n);
    rep(i,0,n)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    int a=v[0].first,b=v[0].second;
    vector<pair<int,int>> ans;
    rep(i,1,n)
    {   
        if(v[i].first>=a and v[i].first<=b)
            b=max(b,v[i].second);
        else
        {
            ans.push_back({a,b});
            a=v[i].first;
            b=v[i].second;
        }
    }
    ans.push_back({a,b});
    rep(i,0,ans.size())
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
