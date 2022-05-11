#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
set<string> ans;
bool search(string s,vector<string> &dict)
{
    for(int i=0;i<dict.size();i++)
    {
        if(s==dict[i])
            return true;
    }
    return false;
}
void driver(string temp,string s,vector<string> &dict,int start,int end)
{
    if(end>=s.length())
    {
        if(start!=end)
        {
            if(search(s.substr(start,end-start+1),dict))
                ans.insert(temp+s.substr(start,end-start+1));
        }
        else
        {
            temp.pop_back();
            ans.insert(temp);
        }
        return;
    }
    string x=s.substr(start,end-start+1);
    if(search(x,dict))
    {
        driver(temp+x+" ",s,dict,end+1,end+1);
    }
    driver(temp,s,dict,start,end+1);
}
vector<string> wordBreak(string &s, vector<string> &dict)
{
    string temp;
    driver(temp,s,dict,0,0);
    vector<string> temp1;
    for(auto it:ans)
        temp1.push_back(it);
    ans.clear();
    return temp1;
}
int32_t main()
{
    string s;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<string> dict(n);
        rep(i,0,n)
            cin>>dict[i];
        cin>>s;
        vector<string> ss=wordBreak(s,dict);
        rep(i,0,ss.size())
            cout<<ss[i]<<endl;
    }
}


