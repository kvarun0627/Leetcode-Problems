class Solution {
public:
    vector<double>pref;
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        pref.assign(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pref[i] = pref[i-1] + (double)nums[i-1];
        }

        vector<vector<double>>DP(n+1,vector<double>(k+1,-1e9));
        DP[0][0] = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                for(int p = 1 ; p<=k ; p++)
                {
                    DP[i][p] = max(DP[i][p] , DP[j][p-1] + (pref[i]-pref[j])/(double)(i-j));
                }
            }
        }
        
        return *max_element(DP[n].begin(),DP[n].end());
    }
};