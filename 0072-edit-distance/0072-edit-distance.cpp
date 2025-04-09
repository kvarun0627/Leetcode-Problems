class Solution {
public:
    int reccur(string word1,string word2,int idx1,int idx2,vector<vector<int>>&DP)
    {
        if(idx1<0 && idx2>=0)
        {
            return idx2+1;
        }
        if(idx1>=0 && idx2<0) return idx1+1;

        if(idx1<0 && idx2<0) return 0;

        if(DP[idx1][idx2]!=-1) return DP[idx1][idx2];

        if(word1[idx1]==word2[idx2])
        {
            return DP[idx1][idx2]=reccur(word1,word2,idx1-1,idx2-1,DP);
        }
        int del=1+reccur(word1,word2,idx1-1,idx2,DP);
        int ins=1+reccur(word1,word2,idx1,idx2-1,DP);
        int rep=1+reccur(word1,word2,idx1-1,idx2-1,DP);
        return DP[idx1][idx2]=min({del,ins,rep});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>DP(m+1,vector<int>(n+1,0));
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            DP[0][i]=i;
        }
        for(int j=1;j<=m;j++)
        {
            DP[j][0]=j;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    DP[i][j]=DP[i-1][j-1];
                }
                else
                {
                    int del=1+DP[i-1][j];
                    int ins=1+DP[i][j-1];
                    int rep=1+DP[i-1][j-1];
                    DP[i][j]=min({del,ins,rep});
                }
            }
        }

        return DP[m][n];
    }
};