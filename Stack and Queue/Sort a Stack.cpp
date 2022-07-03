#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void compare(stack<int> &s,int temp)
{
    stack<int> ss;
    while(!s.empty() and s.top()>temp)
    {
        ss.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!ss.empty())
    {
        s.push(ss.top());
        ss.pop();
    }
}
void sortStack(stack<int> &s)
{
    int temp=s.top();
    s.pop();
    if(s.empty())
        s.push(temp);
    else
    {
        sortStack(s);
        compare(s,temp);
    }
}
void tests()
{
    int n;
    cin>>n;
    stack<int> s;
    rep(i,0,n)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }  
    sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    newline;
}
int32_t main()
{
    fast;
    int t; 
    cin>>t;
    while(t--)
        tests();
    return 0;
}