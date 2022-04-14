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
    int n,m;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    rep(i,0,n)
        cin>>v1[i];
    rep(i,0,m)
        cin>>v2[i];
    int i=0,j=0,k=n-1;
    while(i<n and j<m and i<k)
    {
        if(v1[i]<v2[j])
            i++;
        else
            swap(v2[j++],v1[k--]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    rep(x,0,n)
        cout<<v1[x]<<" ";
    newline;
    rep(x,0,m)
        cout<<v2[x]<<" ";
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
