#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
bool isValid(string s)
{
    stack<char> st;
    if(s[0]==')' or s[0]=='}' or s[0]==']')
        return false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' or s[i]=='[' or s[i]=='{')
            st.push(s[i]);
        else
        {
            if(s[i]==')' and !st.empty() and st.top()=='(')
                st.pop();
            else if(s[i]=='}' and !st.empty() and st.top()=='{')
                st.pop();
            else if(s[i]==']' and  !st.empty() and st.top()=='[')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}
void tests()
{
    string s;
    cin>>s;
    if(isValid(s))
        cout<<"YES";
    else
        cout<<"NO";
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        tests();
}