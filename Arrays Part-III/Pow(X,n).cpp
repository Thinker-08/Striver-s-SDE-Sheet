#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
double calc(double x,int n)
{
    if(x==1 or n==0)
        return 1;
    else
    {
        double temp=calc(x,n/2);
        if(n&1)
        {
            return x*temp*temp;
        }
        else
        {
            return temp*temp;
        }
    }
}
double myPow(double x, int n) {
    double ans=calc(x,abs(n));
    if(n<0)
        return 1/ans;
    return ans;
}
void tests()
{
    double x;int n;
    cin>>x>>n;
    double ans=myPow(x,n);
    cout<<ans;
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
