#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> prevSmaller(vector<int> &arr)
{
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            s.push(i);
        }
        else
        {
            while(!s.empty() and arr[s.top()]>arr[i])
            {
                arr[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        arr[s.top()]=-1;
        s.pop();
    }
    return arr;
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    vector<int> ans=prevSmaller(v);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        tests();
}