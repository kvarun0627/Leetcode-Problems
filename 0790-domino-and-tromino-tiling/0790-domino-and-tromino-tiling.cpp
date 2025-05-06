class Solution {
public:
    int reccur(int idx,bool possible,int n)
    {
        if(idx>n) return 0;

        if(idx==n)
        {
            return !possible;
        }

        if(!possible)
        {
            int domino=reccur(idx+1,false,n)+reccur(idx+2,false,n);
            int tromino=2*reccur(idx+2,true,n);
            return domino+tromino;
        }

        int domino=reccur(idx+1,true,n);
        int tromino=reccur(idx+1,false,n);
        return domino+tromino;
    }
    int mod=1e9+7;
    int numTilings(int n) {
        vector<vector<int>>DP(n+2,vector<int>(2,0));
        DP[n][0]=1;
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int possible=0;possible<=1;possible++)
            {
                if(!possible)
                {
                    int domino=(DP[idx+1][false]+DP[idx+2][false])%mod;
                    int tromino=2*DP[idx+2][true]%mod;
                    DP[idx][possible]=(domino+tromino)%mod;
                }
                else
                {
                    int domino=DP[idx+1][true]%mod;
                    int tromino=DP[idx+1][false]%mod;
                    DP[idx][possible]=(domino+tromino)%mod;
                }
                
            }
        }
        return DP[0][0];
        // return reccur(0,false,n);
    }
};