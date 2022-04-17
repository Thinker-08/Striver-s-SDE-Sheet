#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int ans=0;
void merge(vector<int> &v,int l,int mid,int r)
{
    int i=l,j=mid+1;
    while(i<=mid and j<=r)
    {
        if((long)v[i]>(long)2*v[j])
        {
            ans+=mid-i+1;
            j++;
        }
        else
            i++;
    }
    sort(v.begin()+l,v.begin()+r+1);
}
    
void driver(vector<int> &nums,int l,int r)
{
    if(l>=r)
        return;
    else
    {
        int mid=(l+r)/2;
        driver(nums,l,mid);
        driver(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
}

int reversePairs(vector<int>& nums) {
    driver(nums,0,nums.size()-1);
    return ans;
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int ans1=reversePairs(v);
    cout<<ans1;
    ans=0;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

