#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
int myAtoi(string s)
{
    if(s.length() == 0){
        return 0;
    }
    int i = 0;
    
    while(s[i] == ' '){
        i++;
    }
    bool isPositive = true;
    if(s[i] == '-' || s[i] == '+'){
        isPositive = (s[i] == '+' ? true : false);
        i++;
    }
    if(s[i] - '0' < 0 || s[i] - '0' > 9){
        return 0;
    }
    int num = 0;
   
    while(s[i] >= '0' && s[i] <= '9'){
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] - '0' > 7)){
            return isPositive ? INT_MAX : INT_MIN;
        }

        num = num*10 + (s[i] - '0');
        i++;
   }   
   return isPositive ? num : num*-1;
}
int32_t main()
{ 
    string s;
    cin>>s;
    int ans=myAtoi(s);
    cout<<ans;
}