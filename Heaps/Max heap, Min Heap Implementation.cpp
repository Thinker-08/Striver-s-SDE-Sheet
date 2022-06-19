#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
void heapify(vector<int> &v,int n,int i)
{
    int maxi = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && v[l]>v[maxi])
        maxi=l;
    if(r<n && v[r]>v[maxi])
        maxi=r;
    if(maxi!=i)
    {
        swap(v[maxi],v[i]);
        heapify(v,n,maxi);
    }
}
void heapsort(vector<int>& v)
{
    for(int i=v.size()/2-1;i>=0;i--)
    {
        heapify(v,v.size(),i);
    }
    for(int i=v.size()-1;i>0;i--)
    {
        swap(v[i],v[0]);
        heapify(v,i,0);
    }
    rep(i,0,v.size())
        cout<<v[i]<<" ";
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
    {
        cin>>v[i];
    }
    heapsort(v);
    return 0;
}