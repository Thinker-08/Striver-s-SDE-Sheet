#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int findKthLargest(vector<int>& nums, int k)
{
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[k-1];
}
void tests()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    cout<<(findKthLargest(v,k));
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
