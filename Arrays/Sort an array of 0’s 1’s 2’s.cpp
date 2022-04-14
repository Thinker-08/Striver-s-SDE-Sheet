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
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    int zeros=0,ones=0,twos=0;
    rep(i,0,n)
    {
        if(arr[i]==0)
            zeros++;
        else if(arr[i]==1)
            ones++;
        else
            twos++;
    }
    rep(i,0,n)
    {
        if(zeros)
            arr[i]=0,zeros--;
        else if(ones)
            arr[i]=1,ones--;
        else
            arr[i]=2;
    }
    rep(i,0,n)
        cout<<arr[i]<<" ";
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
