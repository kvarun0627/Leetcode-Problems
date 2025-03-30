class Solution {
public:
    long long DP_memo(vector<int>&a,vector<int>&b,int idx,int trancNo,int n,vector<vector<long long>>&DP)
    {
        if(trancNo==4) return 0;
        if(idx==n) return -1e11;
        if(DP[idx][trancNo]!=LLONG_MIN) return DP[idx][trancNo];
        long long take=(long long)b[idx]*a[trancNo]+DP_memo(a,b,idx+1,trancNo+1,n,DP);
        long long not_take=DP_memo(a,b,idx+1,trancNo,n,DP);
        return DP[idx][trancNo]=max(take,not_take);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<long long>>DP(n+1,vector<long long>(5,LLONG_MIN));
        return DP_memo(a,b,0,0,n,DP);
    }
};