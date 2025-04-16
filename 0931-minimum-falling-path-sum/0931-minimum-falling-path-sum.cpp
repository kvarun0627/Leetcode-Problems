class Solution {
public:
    int Tabulation(vector<vector<int>>& matrix,int n,vector<vector<int>>&DP)
    {
        for(int i=0;i<n;i++)
        {
            DP[n-1][i]=matrix[n-1][i];
        }

        for(int curr_row=n-2;curr_row>=0;curr_row--)
        {
            for(int curr_col=n-1;curr_col>=0;curr_col--)
            {
                int bottom=INT_MAX;
                int left_dia=INT_MAX;
                int right_dia=INT_MAX;
                if(curr_row+1<n)
                {
                    bottom=DP[curr_row+1][curr_col];
                }
                if(curr_row+1<n && curr_col-1>=0)
                {
                    left_dia=DP[curr_row+1][curr_col-1];
                }
                if(curr_row+1<n && curr_col+1<n)
                {
                    right_dia=DP[curr_row+1][curr_col+1];
                }

                DP[curr_row][curr_col]=matrix[curr_row][curr_col]+min({bottom,left_dia,right_dia});
            }
        }
    
        return *min_element(DP[0].begin(),DP[0].end());
    }
    int space_otimization(vector<vector<int>>& matrix,int n)
    {
        vector<int>curr(n,INT_MAX);
        vector<int>prev(n,INT_MAX);

        for(int i=0;i<n;i++)
        {
            prev[i]=matrix[n-1][i];
        }

        for(int curr_row=n-2;curr_row>=0;curr_row--)
        {
            for(int curr_col=n-1;curr_col>=0;curr_col--)
            {
                int bottom=INT_MAX;
                int left_dia=INT_MAX;
                int right_dia=INT_MAX;
                if(curr_row+1<n)
                {
                    bottom=prev[curr_col];
                }
                if(curr_row+1<n && curr_col-1>=0)
                {
                    left_dia=prev[curr_col-1];
                }
                if(curr_row+1<n && curr_col+1<n)
                {
                    right_dia=prev[curr_col+1];
                }

                curr[curr_col]=matrix[curr_row][curr_col]+min({bottom,left_dia,right_dia});
            }
            prev=curr;
        }
    
        return *min_element(prev.begin(),prev.end());
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        // vector<vector<int>>DP(n,vector<int>(n,INT_MAX));
        // return Tabulation(matrix,n,DP);

        return space_otimization(matrix,n);
    }
};