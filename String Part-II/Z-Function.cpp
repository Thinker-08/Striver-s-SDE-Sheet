#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int zAlgorithm(string s, string p, int n, int m)
{
    string fin = p+'$'+s;
    int count=0;
    vector<int> lps(fin.length());
    int i=0,j=1;
    while(j<p.length())
    {
        if(p[i]==p[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
    i=0,j=p.length()+1;
    while(j<fin.length())
    {
        if(fin[j]==fin[i])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
    for(int i=p.length()+1;i<fin.length();i++)
        if(lps[i]==p.length())
               count++;
    return count;
}
int32_t main()
{ 
    string s,pat;
    cin>>s>>pat;
    cout<<(zAlgorithm(s,pat,s.length(),pat.length()));
    newline;
}