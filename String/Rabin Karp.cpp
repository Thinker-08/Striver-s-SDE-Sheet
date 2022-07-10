#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int const MOD=1e9+7;
vector<int> stringMatch(string &str, string &pat) {
    vector<int> ans;
    vector<int> power(str.length());
    for(int i=0;i<str.length();i++)
    {
        if(i==0)
            power[i]=1;
        else
            power[i]=(26*power[i-1])%MOD;
    }
    vector<int> v(str.length());
    for(int i=0;i<str.length();i++)
    {
        if(i==0)
            v[i]=(str[i]-'A'+1)*power[i];
        else
            v[i]=(v[i-1]+(power[i]*(str[i]-'A'+1))%MOD)%MOD;
    }
    int pattern=0;
    for(int i=0;i<pat.length();i++)
        pattern=(pattern+(power[i]*(pat[i]-'A'+1))%MOD)%MOD;
    int temp;
    for(int i=pat.length()-1;i<str.length();i++)
    {
        if(i==pat.length()-1)
            temp=v[i];
        else
            temp=(v[i]-v[i-pat.length()]+MOD)%MOD;
        if(temp==(pattern*power[i-pat.length()+1])%MOD)
        {
            if(i==pat.length()-1)
                ans.push_back(0);
            else
                ans.push_back(i-pat.length()+1);
        }   
    }
    return ans;
}
int32_t main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s,pat;
    cin>>s>>pat;
    vector<int> ans=stringMatch(s,pat);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
        newline;
    }
}