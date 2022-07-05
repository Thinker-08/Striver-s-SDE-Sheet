#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    int i=0,j=0;
    while(j<nums.size())
    {
        pq.push({nums[j],j});
        if(j-i+1<k)
            j++;
        else
        {
            while(pq.top().second<i or pq.top().second>j)
                pq.pop();
            ans.push_back(pq.top().first);
            i++;
            j++;
        }
    }
    return ans;
}
void tests()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i]; 
    vector<int> ans=maxSlidingWindow(v,k); 
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    newline;
}
int32_t main()
{ 
    int t;
    cin>>t;
    while(t--)
        tests();
}
