class Solution {
public:
    // p == -1 : not started
    // p == 0  : started, currently even
    // p == 1  : started, currently odd
    // even -> +
    // odd  -> -

    typedef unordered_map<int, long long> mp;
    typedef vector<mp> vp;
    typedef vector<vp> vvp;
    typedef vector<vvp> vvvp;

    long long memo(int p, int sum, bool tight, int idx, vector<int>& arr, vvvp& DP, int n)
    {
        if (idx == n)
        {
            return (p != -1 && sum == 0);
        }

        if (DP[idx][p + 1][tight].find(sum) != DP[idx][p + 1][tight].end())
        {
            return DP[idx][p + 1][tight][sum];
        }

        int maxi = tight ? arr[idx] : 9;
        long long ans = 0;

        if (p == -1)
        {
            for (int i = 0; i <= maxi; i++)
            {
                bool new_tight = tight && (i == maxi);

                if (i == 0)
                {
                    ans += memo(-1, sum, new_tight, idx + 1, arr, DP, n);
                }
                else
                {
                    ans += memo(1, sum + i, new_tight, idx + 1, arr, DP, n);
                }
            }
        }
        else
        {
            for (int i = 0; i <= maxi; i++)
            {
                bool new_tight = tight && (i == maxi);

                if (p == 0)
                {
                    ans += memo(1, sum + i, new_tight, idx + 1, arr, DP, n);
                }
                else
                {
                    ans += memo(0, sum - i, new_tight, idx + 1, arr, DP, n);
                }
            }
        }

        return DP[idx][p + 1][tight][sum] = ans;
    }

    long long solve(long long high)
    {
        vector<int> arr;
        long long x = high;

        while(x)
        {
            arr.push_back(x % 10);
            x /= 10;
        }

        reverse(arr.begin(), arr.end());
        int n = arr.size();

        vvvp DP(n, vvp(3, vp(2)));
        return memo(-1, 0, true, 0, arr, DP, n);
    }

    long long countBalanced(long long low, long long high)
    {
        return solve(high) - solve(low - 1);
    }
};