class Solution {
public:
    bool DP_MEMO(string&s,string&p,int i,int j,vector<vector<int>>&memo)
    {
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0)
        {
            for(int ii=0;ii<=j;ii++)
            {
                if(p[ii]!='*') return false;
            }
            return true;
        }

        if(memo[i][j]!=-1) return memo[i][j];

        if(s[i]==p[j] || p[j]=='?')
        {
            return memo[i][j]=DP_MEMO(s,p,i-1,j-1,memo);
        }
        else if(p[j]=='*')
        {
            return memo[i][j]=DP_MEMO(s,p,i-1,j,memo)||DP_MEMO(s,p,i,j-1,memo);
        }
        return memo[i][j]=false;
    }

    bool DP_TAB(string&s,string&p,int n,int m,vector<vector<bool>>&tab)
    {
        tab[0][0]=true;
        for(int i=1;i<=n;i++)
        {
            tab[i][0]=false;
        }
        for(int j=1;j<=m;j++)
        {
            bool flag=true;
            for(int jj=1;jj<=j;jj++)
            {
                if(p[jj-1]!='*')
                {
                    flag=false;
                }
            }
            tab[0][j]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    tab[i][j]=tab[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    return tab[i][j]=tab[i][j-1]||tab[i-1][j];
                }
                else tab[i][j]=false;
            }
        }
        return tab[n][m];
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        vector<vector<bool>>tab(n+1,vector<bool>(m+1,-1));
        return DP_MEMO(s,p,n-1,m-1,memo);
        return DP_TAB(s,p,n,m,tab);
    }
};