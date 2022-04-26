#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    return a.second<b.second;
}
int maxMeetings(vector<int> &start, vector<int> &end, int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
        v.push_back({start[i],end[i]});
    sort(v.begin(),v.end(),cmp);
    int count=1,b=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>b)
        { 
            count++;
            b=v[i].second;
        }
    }
    return count;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> start(n),end(n);
    rep(i,0,n)
        cin>>start[i];
    rep(i,0,n)
        cin>>end[i];
    int ans=maxMeetings(start,end,n);
    cout<<ans;
    newline;
}


