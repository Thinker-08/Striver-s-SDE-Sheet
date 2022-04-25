#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {ans=max(ans,count);count=0;}
        }
        ans=max(ans,count);
        return ans;
    }
int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
     int ans=findMaxConsecutiveOnes(v);
     cout<<ans;
     newline;
}


