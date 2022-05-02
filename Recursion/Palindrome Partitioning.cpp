#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<string>> ans;
bool check(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start]==s[end])
        {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}
void driver(string s,vector<string> &temp,int idx)
{
    if(idx>=s.length())
    {
       ans.push_back(temp);
        return;
    }
    else
    {
        for(int i=idx;i<s.length();i++)
        {
            if(check(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                driver(s,temp,i+1);
                temp.pop_back();
            }
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<string> temp;
    string check_str;
    driver(s,temp,0);
    return ans;
}
int32_t main()
{
    string s;
    cin>>s;
    vector<vector<string>> ans=partition(s);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
}


