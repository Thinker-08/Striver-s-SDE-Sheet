#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
string countAndSay(int n)
{
    if(n == 1) {
        return "1";
    }
    
    string result = "1";
    
    for(int i=2;i<=n;i++) {
        char previous = result[0];
        string temp = "";
        int count = 1;
        
        for(int j=1;j<=result.length();j++) {
            if(result[j] != previous) {
                temp = temp + to_string(count) + previous;
                previous = result[j];
                count = 1;
            }else{
                count++;
            }
        }
        result = temp;
    }
    
    return result;
}
int32_t main()
{ 
    int num;
    cin>>num;
    string ans=countAndSay(num);
    cout<<ans;
    return 0;
}