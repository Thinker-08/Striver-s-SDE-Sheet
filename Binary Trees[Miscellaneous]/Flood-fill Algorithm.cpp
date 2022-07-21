void dfs(int i,int j,vector<vector<int>> &image,int initialc,int finalc)
    {
        if(i<0 || j<0)
            return;
        if(i>=image.size() || j>=image[0].size())
            return;
        if(image[i][j]!=initialc)
            return;
        image[i][j]=finalc;
        dfs(i+1,j,image,initialc,finalc);
        dfs(i-1,j,image,initialc,finalc);
        dfs(i,j+1,image,initialc,finalc);
        dfs(i,j-1,image,initialc,finalc);
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            dfs(sr,sc,image,image[sr][sc],newColor);
        return image;
    }