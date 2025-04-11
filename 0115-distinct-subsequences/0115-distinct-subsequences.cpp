class Solution {
public:
    int reccur(string&s,string&t,int i,int j,vector<vector<int>>&DP)
    {
        if(j<0) return 1;
        if(i<0) return 0;

        if(DP[i][j]!=-1) return DP[i][j];

        int skip=reccur(s,t,i-1,j,DP);
        int not_skip=0;
        if(s[i]==t[j])
        {
            not_skip=reccur(s,t,i-1,j-1,DP);
        }
        return DP[i][j]=skip+not_skip;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>DP(n,vector<int>(m,-1));
        return reccur(s,t,n-1,m-1,DP);
    }
};