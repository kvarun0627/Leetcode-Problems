class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
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

            int maxi=INT_MIN;
           for(int c1=1;c1<=n;c1++)
           {
                for(int c2=c1;c2<=n;c2++)
                {
                    multiset<int>st;
                    int sum=0;
                    st.insert(0);
                    for(int r=0;r<m;r++)
                    {
                        sum+=pref_row[r][c2]-pref_row[r][c1-1];
                        int target = sum-k;
                        auto it = lower_bound(st.begin(),st.end(),target);
                        if(it!=st.end())
                        {
                            maxi = max(maxi , sum - *it);
                        }
                        st.insert(sum);
                    }
                }
           }

           return maxi;
    }
};