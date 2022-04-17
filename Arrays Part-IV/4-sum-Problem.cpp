#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void tests()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    rep(i,0, n)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    for(int i=0;i+3<n;i++)
    {
        if(i and v[i]==v[i-1])
            continue;
        for(int j=i+1;j+2<n;j++)
        {
            if(j!=i+1 and v[j]==v[j-1])
                continue;
            int l=j+1,r=v.size()-1;
            int sum=target-v[i]-v[j];
            while(l<r)
            {
                if(v[l]+v[r]==sum){
                    ans.push_back({v[i],v[j],v[l],v[r]});
                    l++;
                    r--;
                    while(l<r and v[l]==v[l-1])
                        l++;
                    while(l<r and v[r]==v[r+1])
                        r--;
                }
                else
                {
                    if(v[l]+v[r]>sum)
                        r--;
                    else
                        l++;
                }
            }
        }
    }
    rep(i,0,ans.size())
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

