//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool check(string a,vector<string> &b)
    {
        for(int i=0;i<b.size();i++)
        {
            if(a==b[i])
                return true;
        }
        return false;
    }
    int find(string a,int idx,vector<string> &b,string temp)
    {
        if(idx>=a.length())
            return 1;
        for(int i=idx;i<a.length();i++)
        {
            temp+=a[i];
            if(check(temp,b))
            {
                return (find(a,i+1,b,"") or find(a,i+1,b,temp));
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
       return find(A,0,B,"");
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends