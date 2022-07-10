#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> lps(string s)
{
    vector<int> v(s.length());
    int i=0,j=1;
    while(j<s.length())
    {
        if(s[i]==s[j])
        {
            v[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=v[i-1];
            }
            else
            {
                v[j]=0;
                j++;
            }
        }
    }
    return v;
}
bool findPattern(string p, string s)
{
    vector<int> v = lps(p); 
    int j=0,i=0;
    while(i<s.length())
    {
        if(p[j]==s[i])
        {
            j++;
            i++;
        }
        if(j==p.size())
        {
            return true;
        }
        else if(i<s.length() and p[j]!=s[i])
        {
            if(j!=0)
                j=v[j-1];
            else
                j=0,i++;
        }
    }
    return false;
}
int32_t main()
{ 
    string s,pat;
    cin>>s>>pat;
    if(findPattern(pat,s))
        cout<<"YES";
    else
        cout<<"NO";
    newline;
}