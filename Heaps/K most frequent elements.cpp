#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> topKFrequent(vector<int>& nums, int k)
{
    map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
    priority_queue<pair<int,int>> pq;
    for(auto it=mp.begin();it!=mp.end();it++)
        pq.push({it->second,it->first});
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
void tests()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,0,n)
        cin>>a[i];
    vector<int> ans=topKFrequent(a,k);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    newline;
}
int32_t main()
{
    fast;
    int t; 
    cin>>t;
    while(t--)
        tests();
    return 0;
}
