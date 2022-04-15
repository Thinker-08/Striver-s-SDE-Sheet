#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>  
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int ans=0;
void merge(vector<int> &v,int l,int mid,int r)
{
    vector<int> temp;
    int i=l,j=mid+1;
    while(i<=mid and j<=r)
    {
        if(v[i]>v[j])
        {
            ans+=mid-i+1;
            temp.push_back(v[j]);
            j++;
        }else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(v[j]);
        j++;
    }
    for(int i=l,j=0;j<temp.size() and i<=r;i++,j++)
    {
        v[i]=temp[j];
    }
}
void driver(vector<int> &v,int l,int r)
{
    if(l>=r)
        return;
    else
    {
        int mid = (l+r)/2;
        driver(v,l,mid);
        driver(v,mid+1,r);
        merge(v,l,mid,r);
    }
}
void tests()
{
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    driver(v,0,v.size()-1);
    cout<<ans;
    newline;
}
int32_t main()
{
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        tests();
        newline;
    }
}
