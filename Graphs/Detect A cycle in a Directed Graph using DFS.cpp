bool check(vector<int> &stack,vector<int> &vis,int vertex,vector<vector<int>> &v)
    {
        stack[vertex]=1;
        if(!vis[vertex])
        {
            vis[vertex]=1;
            for(auto child:v[vertex])
            {
                if(!vis[child] and check(stack,vis,child,v))
                    return true;
                if(stack[child])
                    return true;
            }
        }
        stack[vertex]=0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& pre)
    {
        vector<vector<int>> v(V);
        for(int i=0;i<pre.size();i++)
            v[pre[i][1]].push_back(pre[i][0]);
        vector<int> stack(V,0);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] and check(stack,vis,i,v))
                return false;
        }
        return true;
    }