bool check(int vertex, vector<int> &vis, vector<vector<int>> &adj, vector<int> &path_vis)
    {
        path_vis[vertex] = 1;
        vis[vertex]=1;
        bool flag=false;
        for(auto it: adj[vertex])
        {
            if(vis[it] and path_vis[it])
                return true;
            if(vis[it])
                continue;
            flag |= check(it, vis, adj, path_vis);
        }
        path_vis[vertex]=0;
        return flag;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int> path_vis(num), vis(num);
        for(int i=0;i<num;i++)
        {
            if(check(i, vis, adj, path_vis))
                return false;
        }
        return true;
    }
