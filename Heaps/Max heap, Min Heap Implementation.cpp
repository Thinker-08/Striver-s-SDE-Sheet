#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
void heapify(vector<int> &v,int idx,int end)
{
    int mini=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<=end and v[l]<v[mini])
        mini=l;
    if(r<=end and v[r]<v[mini])
        mini=r;
    if(mini!=idx)
    {
        swap(v[idx],v[mini]);
        heapify(v,mini,end);
    }
}
void insert(vector<int> &v,int val)
{
    v.push_back(val);
    for(int i=v.size()/2-1;i>=0;i--)
        heapify(v,i,v.size()-1);
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
            insert(v,q[i][1]);
        else
        {
            if(v.size()==0)
                ans.push_back(0);
            else
            {
                ans.push_back(v[0]);
                swap(v[0],v[v.size()-1]);
                v.pop_back();
                for(int i=v.size()/2-1;i>=0;i--)
                {
                    heapify(v,i,v.size()-1);
                }
            }
        }
    }
    return ans;
}
void tests(){
    int q;
    cin>>q;
    vector<vector<int>> v;
    rep(i,0,q)
    {
        vector<int> temp;
        int x;
        cin>>x;
        temp.push_back(x);
        if(x==0)
        {
            int y;
            cin>>y;
            temp.push_back(y);
        }
        v.push_back(temp);
    }
    vector<int> ans=minHeap(q,v);
    rep(i,0,ans.size())
        cout<<ans[i]<<" ";
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
