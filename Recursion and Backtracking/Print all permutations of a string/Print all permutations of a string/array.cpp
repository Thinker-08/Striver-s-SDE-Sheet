#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    ans.push_back(nums);
    while(next_permutation(nums.begin(),nums.end()))
        ans.push_back(nums);
    return ans;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    rep(i,0,n)
        cin>>v[i];
    vector<vector<int>> ans=permute(v);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
}


