class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>PM(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                PM[i][j] = mat[i-1][j-1] + PM[i-1][j] + PM[i][j-1] - PM[i-1][j-1];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int row1=i-k;
                int col1=j-k;
                int row2=i+k;
                int col2=j+k;
                if(row1<0) row1=0;
                if(col1<0) col1=0;
                if(row2>=m) row2=m-1;
                if(col2>=n) col2=n-1;

                ans[i][j] = PM[row2+1][col2+1] - PM[row1][col2+1] - PM[row2+1][col1] + PM[row1][col1];
            }
        }
        return ans;
    }
};