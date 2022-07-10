#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int solve(string A) {
    string temp=A;
    reverse(A.begin(),A.end());
    temp+='$'+A;
    vector<int> v(temp.length());
    int i=0,j=1;
    while(j<temp.length())
    {
        if(temp[i]==temp[j])
        {
            v[j]=i+1;
            i++;
            j++;
        }
        else if(temp[j]=='$')
        {
            i=0,j++;
        }
        else if(i!=0)
        {
            i=v[i-1];
        }
        else
        {
            v[j]=0;
            j++;
        }
    }
    return A.length()-v[temp.length()-1];
}
int32_t main()
{ 
    string s;
    cin>>s;
    cout<<solve(s);
    newline;
}