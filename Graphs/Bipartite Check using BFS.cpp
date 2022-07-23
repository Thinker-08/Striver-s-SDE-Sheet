bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;
        vector<int> vis(graph.size());
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i])
                continue;
            q.push({i,1});
            vis[i]=1;
            color[i]=1;
            while(!q.empty())
            {
                pair<int,int> temp=q.front();
                q.pop();
                for(auto it:graph[temp.first])
                {
                    if(color[it]!=-1 and color[it]!=(temp.second)^1)
                        return false;
                    if(vis[it])
                        continue;
                    vis[it]=1;
                    color[it]=(temp.second)^1;
                    q.push({it,color[it]});
                }
            }
        }
        return true;
    }