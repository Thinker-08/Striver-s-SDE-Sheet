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
    bool check=false;
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>> matrix(n,vector<int>(m));
    rep(i,0,n)
        rep(j,0,m)
            cin>>matrix[i][j]; 
    bool check=false;
    for(int i=0;i<matrix.size();i++)
    {
        if(target>matrix[i][matrix[0].size()-1])
            continue;
        else
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==target)
                    check=true;
            }
        }
    }
    cout<<check;
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
