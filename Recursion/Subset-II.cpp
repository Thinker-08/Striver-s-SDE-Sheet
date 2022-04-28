#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<int>> ans;
set<vector<int>> s;
void driver(vector<int> &arr,int idx,vector<int> &temp)
{
    if(idx>=arr.size())
    {
        vector<int> x=temp;
        sort(x.begin(),x.end());
        s.insert(x);
        return;
    }
    else
    {
        driver(arr,idx+1,temp);
        temp.push_back(arr[idx]);
        driver(arr,idx+1,temp);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> temp;
    driver(nums,0,temp);
    for(auto it=s.begin();it!=s.end();it++)
        ans.push_back(*it);
    return ans;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    vector<vector<int>> ans=subsetsWithDup(arr);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
}


