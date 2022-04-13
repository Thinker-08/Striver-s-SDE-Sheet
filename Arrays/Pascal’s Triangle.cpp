#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
const int N=1e5+10;
vector<int> permut(100,1);
void calc(){
    rep(i,1,20)
        permut[i]=i*permut[i-1];
}
void tests()
{
    int n;
    cin>>n;
    vector<vector<int>> rows(n);
    rep(i,0,n)
    {
        rep(j,0,i+1)
        {
            int val = permut[i]/(permut[j]*permut[i-j]);
            rows[i].push_back(val);
        }
    }
    rep(i,0,n)
    {
        rep(j,0,rows[i].size())
            cout<<rows[i][j]<<" ";
        newline;
    }
}
int32_t main()
{
    calc();
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        tests();
        newline;
    }
}
