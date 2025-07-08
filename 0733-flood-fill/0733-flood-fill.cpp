class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int ini=image[sr][sc];
        if(ini==color)
        {
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<pair<int,int>>dir={{0,1},{-1,0},{1,0},{0,-1}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            for(auto [dx,dy]:dir)
            {
                int nx=x+dx;
                int ny=y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==ini)
                {
                    q.push({nx,ny});
                    image[nx][ny]=color;
                }
            }
        }
        return image;
    }
};