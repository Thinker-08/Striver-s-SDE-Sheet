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
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    int mis,repi;
    for(int i=0;i<n;i++)
    {
        if(v[abs(v[i])-1]<0){
            repi=abs(v[i]);
        }
        else
            v[abs(v[i])-1]=-v[abs(v[i])-1];
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
            mis=i+1;
    }
    cout<<repi<<" "<<mis;
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
