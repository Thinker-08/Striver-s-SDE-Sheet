#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    pq.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
    s.insert({A.size()-1,B.size()-1});
    for(int i=0;i<C;i++)
    {
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        if(s.find({temp.second.first-1,temp.second.second})==s.end())
        {
            s.insert({temp.second.first-1,temp.second.second});
            pq.push({A[temp.second.first-1]+B[temp.second.second],{temp.second.first-1,temp.second.second}});
        }
        if(s.find({temp.second.first,temp.second.second-1})==s.end())
        {
            s.insert({temp.second.first,temp.second.second-1});
            pq.push({A[temp.second.first]+B[temp.second.second-1],{temp.second.first,temp.second.second-1}});
        }
    }
    return ans;
}

void tests()
{
    int n,c;
    cin>>n>>c;
    vector<int> a(n),b(n);
    rep(i,0,n)
        cin>>a[i];
    rep(i,0,n)
        cin>>b[i];
    vector<int> ans=solve(a,b,c);
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
