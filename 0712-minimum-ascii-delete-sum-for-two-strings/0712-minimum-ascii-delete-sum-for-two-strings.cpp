class Solution {
public:
    int DP_memo(int idx1,int idx2,vector<vector<int>>&DP,int n,int m,string&s1,string&s2)
    {
        if(idx1<0)
        {
            int sum=0;
            for(int i=idx2;i>=0;i--)
            {
                sum+=s2[i];
            }
            return sum;
        }
        if(idx2<0)
        {
            int sum=0;
            for(int i=idx1;i>=0;i--)
            {
                sum+=s1[i];
            }
            return sum;
        }

        if(DP[idx1][idx2]!=-1) return DP[idx1][idx2];

        if(s1[idx1]==s2[idx2])
        {
            return DP[idx1][idx2]=DP_memo(idx1-1,idx2-1,DP,n,m,s1,s2);
        }
        int first=s1[idx1]+DP_memo(idx1-1,idx2,DP,n,m,s1,s2);
        int second=s2[idx2]+DP_memo(idx1,idx2-1,DP,n,m,s1,s2);
        return DP[idx1][idx2]=min(first,second);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>DP(n,vector<int>(m,-1));
        return DP_memo(n-1,m-1,DP,n,m,s1,s2);
    }
};