#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
string reverseWords(string s)
{
    vector<string> v;
    string temp="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            if(!temp.empty())
                v.push_back(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    v.push_back(temp);
    reverse(v.begin(),v.end());
    temp="";
    for(int i=0;i<v.size();i++)
        if(!v[i].empty())
            temp+=v[i]+' ';
    temp.pop_back();
    return temp;
}
int32_t main()
{ 
    string s;
    getline(cin,s);
    string ans = reverseWords(s);
    cout<<ans;
}
