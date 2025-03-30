class Solution {
public:
    int solve(int num,int partition,vector<vector<int>>&DP)
    {
        if(num==0)
        {
            if(partition<2) return 0;
            return 1;
        }
        if(DP[num][partition]!=-1) return DP[num][partition];

        int ans=0;
        for(int i=1;i<=num;i++)
        {
            ans=max(ans,i*solve(num-i,partition+1,DP));
        }
        return DP[num][partition]=ans;
    }
    int integerBreak(int n) {
        vector<vector<int>>DP(n+1,vector<int>(n+1,-1));
        return solve(n,0,DP);
    }
};