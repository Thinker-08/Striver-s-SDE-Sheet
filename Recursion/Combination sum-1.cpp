#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
set<vector<int>> s;
void driver(vector<int> &arr,int target,vector<int> &temp,int sum,int idx)
{
    if(sum>target)
        return;
    if(sum==target)
    {
        s.insert(temp);
        return;
    }
    else
    {
        for(int i=idx;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            driver(arr,target,temp,sum+arr[i],i);
            temp.pop_back();
        }
    }
        
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<int> temp;
    driver(candidates,target,temp,0,0);
    vector<vector<int>> ans;
    for(auto it=s.begin();it!=s.end();it++)
        ans.push_back(*it);
    return ans;
}
int32_t main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    vector<vector<int>> ans=combinationSum(arr,target);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
}


