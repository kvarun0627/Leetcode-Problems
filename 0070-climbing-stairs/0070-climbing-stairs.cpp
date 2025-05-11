class Solution {
public:
    int memo(int n,vector<int>&DP)
    {
        if(n==1 || n==0) return 1;
        
        if(DP[n]!=-1) return DP[n];

        return DP[n]=memo(n-1,DP)+memo(n-2,DP);
    }
    int climbStairs(int n) {
        vector<int>DP(n+1,-1);
        return memo(n,DP);
    }
};