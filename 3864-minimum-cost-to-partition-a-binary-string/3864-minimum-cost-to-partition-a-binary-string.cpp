class Solution {
public:
    vector<long long>pref;
    long long solve(int l, int r, int e ,int f)
    {
        long long cost;
        int ones = pref[r+1]-pref[l];
        int len = (r-l+1);
        if(ones == 0)
        {
            cost = f;
        }
        else if(ones > 0)
        {
            cost = 1LL * len * ones * e;
        }

        if(len & 1)
        {
            return cost;
        }

        int m = (l+r)/2;
        long long left = solve(l,m,e,f);
        long long right = solve(m+1,r,e,f);
        return min(cost,left+right);
    }
    long long minCost(string s, int encCost, int flatCost) 
    {
        int n=s.size();
        pref.assign(n+1,0);
        for(int i=1; i<=n ; i++)
        {
            pref[i] = pref[i-1] + (long long)(s[i-1]-'0');
        }
        return solve(0 , n-1 , encCost , flatCost);
    }
};