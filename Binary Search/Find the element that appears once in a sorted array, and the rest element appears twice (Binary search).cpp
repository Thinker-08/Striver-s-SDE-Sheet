#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int singleNonDuplicate(vector<int>& nums)
{
    int lo=0,hi=nums.size()-1;
    while(hi>lo)
    {
        int mid=(hi+lo)/2;
        if(mid%2==1)
        {
            if(nums[mid]==nums[mid-1])
                lo=mid+1;
            else
                hi=mid;
        }
        else
        {
            if(nums[mid]==nums[mid+1])
                lo=mid+1;
            else
                hi=mid;
        }
    }
    return nums[hi];
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    cout<<(singleNonDuplicate(v));
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

