#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
bool check(int test,vector<int> &v,int cows)
{
    int pos=v[0];
    cows--;
    for(int i=1;i<v.size() and cows!=0;i++)
    {
        if(v[i]-pos>=test)
        {
            cows--;
            pos=v[i];
        }
    }
    if(cows==0)
        return true;
    else
        return false;
}
void tests()
{
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    sort(v.begin(),v.end());
    int lo=0,hi=1e11;
    while(hi-lo>1)
    {
        int mid=(lo+hi)/2;
        if(check(mid,v,c))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(check(hi,v,c))
        cout<<hi;
    else
        cout<<lo;
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        tests();
    }
    return 0;
}