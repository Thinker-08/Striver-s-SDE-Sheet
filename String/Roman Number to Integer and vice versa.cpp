#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int romanToInt(string s)
    {
        map<char,int> mp;
     mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;mp['C']=100;mp['D']=500;mp['M']=1000;
        int ans=mp[s[0]];
        for(int i=1;i<s.length();i++)
        {
            if(mp[s[i-1]]<mp[s[i]])
            {
                ans=ans+mp[s[i]]-2*mp[s[i-1]];
            }
            else
                ans+=mp[s[i]];
        }
        return ans;
    }
int32_t main()
{ 
    string s;
    cin>>s;
    int ans=romanToInt(s);
    cout<<ans;
}