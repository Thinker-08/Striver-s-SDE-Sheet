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
    string s;
    cin>>s;
    unordered_set<int> st;
    int i=0,j=0,ans=0;
    while(j<s.length())
    {
        if(st.find(s[j])==st.end())
        {
            st.insert(s[j]);
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            while(st.find(s[j])!=st.end())
            {
                st.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
    newline;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        tests();
}

