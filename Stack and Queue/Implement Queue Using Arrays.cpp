#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
vector<int> v;
int i,j;
bool isEmpty() {
    if(i==j)
        return true;
    else
        return false;
}

void enqueue(int data) {
    v.push_back(data);
    j++;
}

int dequeue() {
    if(i==j)
        return -1;
    i++;
    return v[i-1];
}

int front() {
    if(i==j)
        return -1;
    return v[i];
}
void tests()
{
    i=0,j=0;
    int q;
    cin>>q;
    rep(k,0,q)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int y;
            cin>>y;
            enqueue(y);
        }
        else if(x==2)
        {
            int ans=dequeue();
            cout<<ans<<" ";
        }
        else if(x==3)
        {
            int ans=front();
            cout<<ans<<" ";
        }
        else
        {
            cout<<(isEmpty());
        }
    }
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
