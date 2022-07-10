#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
static bool cmp(string a,string b)
{
    return a.length()<b.length();
}
string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end(),cmp);
    string ans="";
    for(int i=0;i<strs[0].length();i++)
    {
        for(int j=0;j<strs.size();j++)
        {
            if(strs[0][i]==strs[j][i])
                continue;
            else
                return ans;
        }
        ans+=strs[0][i];
    }
    return ans;
}
int32_t main()
{ 
    int n;
    cin>>n;
    vector<string> v(n);
    rep(i,0,n)
        cin>>v[i];
    string ans=longestCommonPrefix(v);
    cout<<ans;
}