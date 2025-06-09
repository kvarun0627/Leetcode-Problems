class Solution {
public:
    // bool reccur(int idx1,int idx2,int idx3,string&s1, string&s2, string&s3,vector<vector<int>>&DP)
    // {
    //     if(idx3<0 && (idx1>=0 || idx2>=0))
    //     {
    //         return false;
    //     }
    //     if(idx1<0 && (idx3>=0 && idx2>=0))
    //     {
    //         while(idx3>=0 && idx2>=0)
    //         {
    //             if(s3[idx3]!=s2[idx2])
    //             {
    //                 return false;
    //             }
    //             idx3--;
    //             idx2--;
    //         }
    //         return idx3<0 && idx2<0;
    //     }
    //     if(idx2<0 && (idx1>=0 && idx3>=0))
    //     {
    //         while(idx3>=0 && idx1>=0)
    //         {
    //             if(s3[idx3]!=s1[idx1])
    //             {
    //                 return false;
    //             }
    //             idx1--;
    //             idx3--;
    //         }
    //         return idx3<0 && idx1<0;
    //     }

    //     if(DP[idx1][idx2]!=-1)
    //     {
    //         return DP[idx1][idx2];
    //     }

    //     if(s1[idx1]==s3[idx3] && s2[idx2]==s3[idx3])
    //     {
    //         return DP[idx1][idx2]=reccur(idx1-1,idx2,idx3-1,s1,s2,s3,DP) || reccur(idx1,idx2-1,idx3-1,s1,s2,s3,DP);
    //     }
    //     if(s1[idx1]==s3[idx3])
    //     {
    //         return DP[idx1][idx2]=reccur(idx1-1,idx2,idx3-1,s1,s2,s3,DP);
    //     }
    //     if(s2[idx2]==s3[idx3])
    //     {
    //         return DP[idx1][idx2]=reccur(idx1,idx2-1,idx3-1,s1,s2,s3,DP);
    //     }
    //     return DP[idx1][idx2]=false;
    // }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();

        if(k==0 && n==0 && m==0)
        {
            return true;
        }
        if(n+m!=k)
        {
            return false;
        }
        if(k>0 && n==0)
        {
            return s3==s2;
        }
        if(k>0 && m==0)
        {
            return s3==s1;
        }

        // vector<vector<bool>>DP(n+1,vector<bool>(m+1,false));
        // DP[0][0]=true;
        // for(int i=1;i<=min(n,k);i++)
        // {
        //     if(s1[i-1]!=s3[i-1])
        //     {
        //         break;
        //     }
        //     DP[i][0]=true;
        // }
        // for(int i=1;i<=min(m,k);i++)
        // {
        //     if(s2[i-1]!=s3[i-1])
        //     {
        //         break;
        //     }
        //     DP[0][i]=true;
        // }
        vector<int>curr(m+1,false),prev(m+1,false);
        prev[0]=true;
        for(int i=1;i<=min(m,k);i++)
        {
            if(s2[i-1]!=s3[i-1])
            {
                break;
            }
            prev[i]=true;
        }
        for(int idx1=1;idx1<=n;idx1++)
        {
            curr[0]=(s1[idx1 - 1] == s3[idx1 - 1]) && prev[0];
            for(int idx2=1;idx2<=m;idx2++)
            {
                int idx3=idx1+idx2;
                if(s1[idx1-1]==s3[idx3-1] && s2[idx2-1]==s3[idx3-1])
                {
                    curr[idx2]=prev[idx2] || curr[idx2-1];
                }
                else if(s1[idx1-1]==s3[idx3-1])
                {
                    curr[idx2]=prev[idx2];
                }
                else if(s2[idx2-1]==s3[idx3-1])
                {
                    curr[idx2]=curr[idx2-1];
                }
                else
                {
                    curr[idx2]=false;
                }
            }
            prev=curr;
        }
        
        return prev[m];

        // return reccur(n-1,m-1,k-1,s1,s2,s3,DP);
    }
};