class Solution 
{
    public:
        long long maximumSum(vector<int>& nums, int m, int l, int r)
        {
            int n = nums.size();
            vector<long long>pref(n+1,0);
            for(int i=1 ; i<=n ; i++)
            {
                pref[i] = pref[i-1] + nums[i-1];
            }

            vector<vector<long long>>DP(n+1,vector<long long>(m+1,-1e15));

            //DP[i][j] = maximum total sum , i can acheive after forming atmost j subarrays with first i index

            //transistion state = DP[i][j] = max(DP[i-1][j] , max of for k in range (i-l , i-r) pref[i] - pref[k] + DP[k][j-1])

            //DP[i][j] = max(DP[i-1][j] , pref[i] + max(DP[k][j-1]-pref[k]))

            for(int i=0 ; i<=n ; i++)
            {
                DP[i][0] = 0;
            }

            for(int j = 1 ; j <= m ; j++)
            {
                multiset<long long>st;

                for(int i = 1 ; i <= n ; i++)
                {
                    DP[i][j] = DP[i-1][j];

                    int ins = i - l;
                    int del = i - r;

                    if(ins >= 0)
                        st.insert(DP[ins][j-1] - pref[ins]);

                    

                    if(!st.empty())
                        DP[i][j] = max(DP[i][j], pref[i] + *st.rbegin());
                        
                    if(del >= 0)
                    {
                        auto it = st.find(DP[del][j-1] - pref[del]);
                        if(it != st.end()) st.erase(it);
                    }
                }
            }

            long long ans = -1e15;
            for(int i=1 ; i<=n ; i++)
            {
                for(int j = 1; j <= m ; j++)
                {
                    ans = max(ans,DP[i][j]);
                }
            }

            return ans;
        }
};