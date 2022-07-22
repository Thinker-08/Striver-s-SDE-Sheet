bool ans=true;
    void check(vector<int> &vis,vector<int> &color,vector<vector<int>> &graph,int vertex,int col)
    {
        if(color[vertex]!=-1 and color[vertex]!=col)
        {
            ans=false;
            return;
        }
        if(vis[vertex])
            return;
        vis[vertex]=1;
        color[vertex]=col;
        for(auto it:graph[vertex])
        {
            check(vis,color,graph,it,(col^1));
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size());
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
                check(vis,color,graph,i,1);
        }   
        return ans;
    }