class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int row=0;
        for(int i=0;i<n;i++)
        {
            int r=m-1;int l=0;
            while(l<=r)
            {
                if(grid[i][l]!=grid[i][r])
                {
                    row++;
                }
                l++;
                r--;
            }
        }

        int col=0;
        for(int i=0;i<m;i++)
        {
            int l=0;
            int r=n-1;
            while(l<=r)
            {
                if(grid[l][i]!=grid[r][i])
                {
                    col++;
                }
                l++;
                r--;
            }
        }

        return min(row,col);
    }
};