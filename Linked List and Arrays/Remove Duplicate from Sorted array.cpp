#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int removeDuplicates(vector<int>& nums)
{
    int idx=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==nums[i-1])
            continue;
        else
        {
            nums[idx]=nums[i];
            idx++;
        }
    }
    return idx;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
     int ans=removeDuplicates(v);
     cout<<ans;
     newline;
}


