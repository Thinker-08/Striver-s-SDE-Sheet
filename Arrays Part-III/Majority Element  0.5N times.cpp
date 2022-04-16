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
    int pos_ans=-1,count=0;
    rep(i,0,n)
    {
        if(count==0){
            count=1;
            pos_ans=v[i];
        }else{
            if(pos_ans==v[i])
                count++;
            else
                count--;
        }
    }
    count=0;
    rep(i,0,n)
        if(pos_ans==v[i])
            count++;
    if(count>n/2)
        cout<<pos_ans;
    else
        cout<<-1;
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

