#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int compareVersion(string version1, string version2)
{
    int result;
    queue<int> q1, q2;
    stringstream ss1(version1), ss2(version2);
    string token;
    while(getline(ss1, token, '.')){
        q1.push(stoi(token));
    }
    while(getline(ss2, token, '.')){
        q2.push(stoi(token));
    }
    while(!q1.empty() && !q2.empty()){
        if(q1.front() == q2.front()){
            q1.pop(); q2.pop();
        }else{
            if(q1.front() > q2.front()) return 1;
            else return -1;
        }
    }
    if(q1.empty() && q2.empty()) return 0;
    while(!q1.empty()){
        if(q1.front() > 0) return 1;
        else q1.pop();
    }
    while(!q2.empty()){
        if(q2.front() > 0) return -1;
        else q2.pop();
    }
    return 0;
}
int32_t main()
{ 
    string n1,n2;
    cin>>n1>>n2;
    int ans=compareVersion(n1,n2);
    cout<<ans;
}