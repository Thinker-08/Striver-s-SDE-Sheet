#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int findPlatform(vector<int> &arr,vector<int> &dep, int n)
{
    int count=0,i=0,j=0,ans=0;
    sort(arr.begin(),arr.end());sort(dep.begin(),dep.end());
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans=max(count,ans);
    }
    return ans;
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> start(n),end(n);
    rep(i,0,n)
        cin>>start[i];
    rep(i,0,n)
        cin>>end[i];
    int ans=findPlatform(start,end,n);
    cout<<ans;
    newline;
}


