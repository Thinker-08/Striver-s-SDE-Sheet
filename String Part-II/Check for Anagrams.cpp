#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        for(int i=0;i<t.length();i++)
            mp[t[i]]--;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second!=0)
                return false;
        }
        return true;
    }
int32_t main()
{ 
    string s,t;
    cin>>s>>t;
    if(isAnagram(s,t))
        cout<<"YES";
    else
        cout<<"NO";
    newline;
}