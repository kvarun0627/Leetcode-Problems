class Solution {
public:
    long long nthSmallest(long long n, int k) 
    {
        vector<vector<long long>>comb(50, vector<long long>(50, 0));
        for(int i = 0; i < 50; i++)
        {
            comb[i][0] = comb[i][i] = 1;
            for(int j = 1; j < i; j++)
            {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }

        auto nCr = [&](int n, int r)
        {
            if(r > n || r < 0) return 0LL;
            return comb[n][r];
        };

        int MSB=k-1;
        long long ans=0;
        while(k>0)
        {
            long long cnt = nCr(MSB,k-1);
            if(n>cnt)
            {
                n-=cnt;
                MSB++;
            }
            else
            {
                ans = ans | (1LL<<(MSB));
                MSB=0;
                k--;
            }
        }

        return ans;
    }
};