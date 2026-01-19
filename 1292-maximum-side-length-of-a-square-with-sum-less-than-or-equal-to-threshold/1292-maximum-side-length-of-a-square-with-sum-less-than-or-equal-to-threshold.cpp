class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>DP(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                DP[i][j]=mat[i-1][j-1]+DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1];
            }
        }

        auto check=[&](int len)
        {
            int mini=INT_MAX;
            for(int i=0;i+len<=m;i++)
            {
                for(int j=0;j+len<=n;j++)
                {
                    int x1=i;
                    int y1=j;
                    int x2=i+len;
                    int y2=j+len;

                    int sum=DP[x2][y2]-DP[x1][y2]-DP[x2][y1]+DP[x1][y1];
                    mini=min(mini,sum);
                }
            }
            return mini <= threshold;
        };
        int high=min(m,n); 
        int low=1;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }  

        return ans;
    }
};