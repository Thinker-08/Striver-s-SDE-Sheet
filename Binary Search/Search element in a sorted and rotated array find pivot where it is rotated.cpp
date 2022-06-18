#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int find_in(vector<int> &nums,int target,int lo,int hi)
{
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if(nums[mid]>target)
            hi=mid-1;
        else
            lo=mid;
    }
    if(nums[lo]==target)
        return lo;
    if(nums[hi]==target)
        return hi;
    return -1;
}
int search(vector<int>& nums, int target) 
{
    if(nums.size()==1)
    {
        if(nums[0]==target)
            return 0;
        else 
            return -1;
    }
    int lo=0,hi=nums.size()-1;
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if(nums[mid]>nums[hi])
            lo=mid;
        else
            hi=mid;
    }
    int a=find_in(nums,target,0,hi-1);
    if(a!=-1)
        return a;
    a=find_in(nums,target,hi,nums.size()-1);
    if(a!=-1)
        return a;
    return -1;
}
void tests()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    cout<<(search(v,target));
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

