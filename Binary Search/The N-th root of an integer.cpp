#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
double BinaryExpo(double a, long long b)
{
    if(b==0)
        return 1;
    double res = BinaryExpo(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}
double findNthRootOfM(int n, long long m) {
    double lo=0,hi=m;
    while(hi-lo>1e-8)
    {
        double mid=(hi+lo)/2;
        if(BinaryExpo(mid,n)>m)
            hi=mid;
        else
            lo=mid;
    }
    return lo;
}

void tests()
{
    int n,m;
    cin>>n>>m;
    cout<<(findNthRootOfM(n,m));
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

