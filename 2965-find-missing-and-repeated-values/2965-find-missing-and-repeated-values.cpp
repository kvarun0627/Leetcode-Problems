class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n*n;
        int sum=m*(m+1)/2;
        int sum1=0;
        vector<int>v(m,0);
        vector<int>ans(2);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[grid[i][j]-1]!=1)
                {
                    sum1+=grid[i][j];
                }
                else
                {
                    ans[0]=grid[i][j];
                }
                v[grid[i][j]-1]++;
            }
        }
        ans[1]=sum-sum1;
        return ans;


    }
};