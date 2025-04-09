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
        vector<vector<int>>DP(word1.size(),vector<int>(word2.size(),-1));
        return reccur(word1,word2,word1.size()-1,word2.size()-1,DP);
    }
};