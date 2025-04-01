class Solution {
public:
    long long solve(vector<vector<int>>& questions,int n,int idx,vector<long long>&DP)
    {
        if(idx>=n) return 0;
        if(DP[idx]!=-1) return DP[idx];
        long long not_skip=questions[idx][0]+solve(questions,n,idx+questions[idx][1]+1,DP);
        long long skip=solve(questions,n,idx+1,DP);
        return DP[idx]=max(skip,not_skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>DP(n,-1);
        return solve(questions,n,0,DP);
    }
};