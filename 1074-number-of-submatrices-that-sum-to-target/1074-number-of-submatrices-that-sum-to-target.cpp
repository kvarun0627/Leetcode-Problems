class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>pref_row(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pref_row[i][j] = pref_row[i][j-1] + matrix[i][j-1];
            }
        }

        int ans=0;
        for(int c1=1;c1<=n;c1++)
        {
            for(int c2=c1;c2<=n;c2++)
            {
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int r=0;r<m;r++)
                {   
                    sum+=(pref_row[r][c2]-pref_row[r][c1-1]);
                    if(mp.find(sum-target)!=mp.end())
                    {
                        ans+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};