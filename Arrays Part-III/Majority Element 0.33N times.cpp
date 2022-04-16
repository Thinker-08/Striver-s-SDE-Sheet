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
    int first=INT_MAX,second=INT_MAX,count1=0,count2=0;
    rep(i,0,n)
    {
        if(v[i]==first)
            count1++;
        else if(v[i]==second)
            count2++;
        else if(count1==0){
            count1++;
            first=v[i];
        }else if(count2==0){
            count2=1;
            second=v[i];
        }else{
            count1--;
            count2--;
        }
    }
    count1=0,count2=0;
    rep(i,0,n)
    {
        if(v[i]==first)
            count1++;
        else if(v[i]==second)
            count2++;
    }
    if(count1>n/3)
        cout<<first<<" ";
    else if(count2>n/3)
        cout<<second;
    newline;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

