#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static const int N=1e5;
	int parent[N];
	int siz[N];
	void make(int a)
	{
	    parent[a]=a;
	    siz[a]=1;
	}
	int find(int a)
	{
	    if(parent[a]==a)
	        return a;
	    else
	    {
	        parent[a]=find(parent[a]);
	        return parent[a];
	    }
	}
	void Union(int a,int b)
	{
	    a=find(a);
	    b=find(b);
	    if(a==b)
	        return;
	    else
	    {
	        if(siz[a]<siz[b])
	        {
	            parent[a]=b;
	            siz[b]+=siz[a];
	        }
	        else
	        {
	            parent[b]=a;
	            siz[a]+=siz[b];
	        }
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        for(int i=0;i<V;i++)
        {
            make(i);
        }
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                edges.push_back({adj[i][j][1],{i,adj[i][j][0]}});
            }
        }
        int ans=0;
        sort(edges.begin(),edges.end());
        for(auto edge:edges)
        {
            if(find(edge.second.first)==find(edge.second.second))
                continue;
            Union(edge.second.first,edge.second.second);
            ans+=edge.first;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends