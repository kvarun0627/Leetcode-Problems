class Solution {
public:
    // int fn()
    int countNumbersWithUniqueDigits(int n) {
        vector<int>DP(9,0);
        vector<int>G(9,0);
        DP[0]=1;
        DP[1]=10;
        G[1]=9;
        for(int i=2;i<=n;i++)
        {
            G[i]=(11-i)*G[i-1];
            DP[i]=DP[i-1]+G[i];
        }
        return DP[n];
    }
};