#include <bits/stdc++.h>
using namespace std;
bool safe_to_color(bool graph[101][101],int src,vector<int> &color,int k)
{
    for(int i=0;i<101;i++)
    {
        if(graph[src][i])
        {
            if(color[i]==k)
                return false;
        }
    }
    return true;
}
bool coloring(bool graph[101][101],vector<int> &color,int m,int src)
{
    if(src>=color.size())
        return true;
    else
    {
        for(int k=1;k<=m;k++)
        {
            if(safe_to_color(graph,src,color,k))
            {
                color[src]=k;
                if(coloring(graph,color,m,src+1))
                    return true;
            }
            color[src]=0;
        }
        return false;
    }
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V,0);
    return coloring(graph,color,m,0);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}