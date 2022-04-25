#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<int>> threeSum(vector<int>& nums) 
{
    if(nums.size()==0 or nums.size()==1 or nums.size()==2)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    set<vector<int>> s;
    for(int i=0;i<nums.size()-2;i++)
    {
        int l=i+1,r=nums.size()-1;
        while(l<r)
        {
            if(nums[i]+nums[l]+nums[r]<0)
            {
                l++;
            }
            else
            {
                if(nums[i]+nums[l]+nums[r]>0)
                {
                    r--;
                }
                else
                {
                    s.insert({nums[i],nums[l],nums[r]});
                    r--;
                }
            }
        }
    }
    for(auto it=s.begin();it!=s.end();it++)
        ans.push_back(*it);
    return ans;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
     vector<vector<int>> ans=threeSum(v);
    rep(i,0,ans.size())
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
}


