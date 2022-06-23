#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> mergeKSortedArrays(vector<vector<int>>&v, int k)
{
    priority_queue<int> pq;
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            pq.push(v[i][j]);
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void tests()
{
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    rep(i,0,n)
    {
        int x;
        cin>>x;
        rep(j,0,x)
        {
            int temp;
            cin>>temp;
            a[i].push_back(temp);
        }
    }
    vector<int> ans=mergeKSortedArrays(a,n);
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
