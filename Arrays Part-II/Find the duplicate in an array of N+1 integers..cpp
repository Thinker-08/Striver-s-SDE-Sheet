#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void tests()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    rep(i,0,n)
        cin>>nums[i];
    int fasti=nums[0],slow=nums[0];
    do{
        slow=nums[slow];
        fasti=nums[nums[fasti]];
    }while(slow!=fasti);
    fasti=nums[0];
    while(slow!=fasti)
    {
        slow=nums[slow];
        fasti=nums[fasti];
    }
    cout<<slow;
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        tests();
        newline;
    }
}
