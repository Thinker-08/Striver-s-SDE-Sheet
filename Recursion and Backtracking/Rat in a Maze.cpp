// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    vector<pair<int,int>> moves={
        {1,0},{0,1},{-1,0},{0,-1}
    };
    void driver(string temp,vector<vector<int>> &mat,int i,int j,vector<vector<int>> &vis)
    {
        if(i==mat.size()-1 and j==mat.size()-1)
        {
            ans.push_back(temp);
            return;
        }
        vis[i][j]=1;
        for(auto it:moves)
        {
            if(i+it.first>=mat.size() or i+it.first<0 or j+it.second>=mat.size() or j+it.second<0)
                continue;
            if(mat[i+it.first][j+it.second]==0)
                continue;
            if(vis[i+it.first][j+it.second])
                continue;
            if(it.first==1 and it.second==0)
                driver(temp+'D',mat,i+it.first,j+it.second,vis);
            if(it.first==-1 and it.second==0)
                driver(temp+'U',mat,i+it.first,j+it.second,vis);
            if(it.first==0 and it.second==1)
                driver(temp+'R',mat,i+it.first,j+it.second,vis);
            if(it.first==0 and it.second==-1)
                driver(temp+'L',mat,i+it.first,j+it.second,vis);
        }   
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==0)
            return {};
        driver(temp,m,0,0,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends