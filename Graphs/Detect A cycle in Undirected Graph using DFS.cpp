//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int const N=1e5+10;
    bool ans=false;
    void dfs(vector<int> adj[],vector<int> &vis,int vertex,int parent)
    {
        vis[vertex]=1;
        for(auto idx:adj[vertex])
        {
            if(idx==parent)
                continue;
            if(vis[idx])
            { 
                ans=true;
                continue;
            }
            dfs(adj,vis,idx,vertex);
        }
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(N,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i])
                continue;
            dfs(adj,vis,i,-1);
            if(ans)
                break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends