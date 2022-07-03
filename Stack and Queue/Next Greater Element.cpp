#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> s;
    vector<int> v,ans;
    for(int i=0;i<nums2.size();i++)
        v.push_back(nums2[i]);
    for(int i=0;i<nums2.size();i++)
    {
        if(s.empty())
            s.push(i);
        else
        {
            while(!s.empty() and nums2[i]>nums2[s.top()])
            {
                nums2[s.top()]=nums2[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        nums2[s.top()]=-1;
        s.pop();
    }
    map<int,int> mp;
    for(int i=0;i<nums2.size();i++)
        mp[v[i]]=nums2[i];
    for(int i=0;i<nums1.size();i++)
        ans.push_back(mp[nums1[i]]);
    return ans;

}
void tests()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    rep(i,0,n)
        cin>>v1[i];
    rep(i,0,m)
        cin>>v2[i];
    vector<int> ans=nextGreaterElement(v1,v2);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
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