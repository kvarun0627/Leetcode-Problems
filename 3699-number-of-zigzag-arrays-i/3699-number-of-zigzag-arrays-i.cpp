
class Solution {
public:
    // int memo(int idx,int l,int r,int prev,int dir)
    // {
    //     if(idx<0)
    //     {
    //          return 1;
    //     }
    //     int ans=0;
    //     if(dir==0)//go down
    //     {
    //         for(int i=l;i<prev;i++)
    //         {
    //             ans=ans+memo(idx-1,l,r,i,1);
    //         }
    //     }
    //     else if(dir==1)//go up
    //     {
    //         for(int i=prev+1;i<=r;i++)
    //         {
    //             ans=ans+memo(idx-1,l,r,i,0);
    //         }
    //     }
    // }
    
    int zigZagArrays(int n, int l, int r) 
    {
        int m=(r-l+1);
        int mod=1e9+7;
        vector<vector<int>>pre(m,vector<int>(2,1));
        vector<vector<int>>curr(m,vector<int>(2,0));
        //DP[idx][prev][dir] --> for current index with given previous element with current dir how many zig zag array can be formed
        //dir -- > 0(going down)
        //dir --> 1(goind up)
        // for(int prev=0;prev<m;prev++)
        // {

        //     pre[prev][1]=1;
        //     pre[prev][0]=1;
        // }
        for(int i=1;i<n;i++)
        {
            int suff=0;
            for(int k=0;k<m;k++)
            {
                suff=(suff+pre[k][1])%mod;
                curr[k][0]=curr[k][1]=0;
            }
            int pref=0;
            for(int prev=0;prev<m;prev++)
            {
                // for(int j=0;j<prev;j++)
                // {
                //     DP[i][prev][1]=(DP[i][prev][1]+DP[i-1][j][0])%mod; // simply DP[i][prev][1] is sum of 
                // }
                // for(int j=prev+1;prev<m;j++)
                // {
                //     DP[i][prev][0]=(DP[i][prev][0]+DP[i-1][j][1])%mod;
                // }

                curr[prev][1]=(curr[prev][1]+pref)%mod;
                pref=(pref+pre[prev][0])%mod;
                suff=(suff-pre[prev][1]+mod)%mod;
                curr[prev][0]=(curr[prev][0]+suff)%mod;
            }
            pre=curr;
        }

        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans=(ans+pre[i][0])%mod;
            ans=(ans+pre[i][1])%mod;
        }

        return ans;
    }
};