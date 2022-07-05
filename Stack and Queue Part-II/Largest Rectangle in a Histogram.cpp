#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int largestRectangleArea(vector<int>& arr)
{
    vector<int> left(arr.size()),right(arr.size());
    stack<int> s;
    for(int i=0;i<arr.size();i++)
    {
        if(s.empty())
        {
            left[i]=0;
            s.push(i);
        }
        else
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
                s.pop();
            left[i]=s.empty()?0:s.top()+1;
            s.push(i);
        }
    }
    while(!s.empty())
        s.pop();
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            right[i]=arr.size()-1;
            s.push(i);
        }
        else
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
                s.pop();
            right[i]=s.empty()?arr.size()-1:s.top()-1;
            s.push(i);
        }
    }
    int ans=INT_MIN;   
    for(int i=0;i<arr.size();i++)
    {
        ans=max(ans,arr[i]*(right[i]-left[i]+1));
    }
    return ans;
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    cout<<(largestRectangleArea(v));    
}
int32_t main()
{ 
    int t;
    cin>>t;
    while(t--)
        tests();
}
