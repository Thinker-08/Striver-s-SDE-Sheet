#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
string next_permut(string s)
{
    if(s.length()==1)
        return s;
    int i=s.length()-2;
    while(i>=0 and s[i]>s[i+1])
        i--;
    pair<char,int> p={'a',INT_MAX};
    for(int x=i+1;x<s.length();x++)
    {
        if(s[x]>s[i])
            if(p.first>s[x])
                p={s[x],x};
    }
    swap(s[p.second],s[i]);
    reverse(s.begin()+i+1,s.end());
    return s;
}
string getPermutation(int n, int k) {
    string s;
    for(int i=1;i<=n;i++)
        s+=to_string(i);
    int count=1; 
    while(count<k)
    {
        s=next_permut(s);
        count++;
    }
    return s;
}
int32_t main()
{
    int n,k;
    cin>>n>>k;
    string ans=getPermutation(n,k);
    cout<<ans;
}


