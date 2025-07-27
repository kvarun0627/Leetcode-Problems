class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<int>preL(n+1,0),sufT(n+1,0),preLC(n+1,0),sufCT(n+1,0);
        for(int i=0;i<n;i++)
        {
            preL[i+1]=preL[i]+(s[i]=='L');
            sufT[n-i-1]=sufT[n-i]+(s[n-i-1]=='T');
            sufCT[n-i-1]=sufCT[n-i] + (s[n-i-1]=='C'?sufT[n-i]:0);
            preLC[i+1]=preLC[i] + (s[i]=='C'?preL[i]:0);
        }

        long long base=0;
        long long gains=max(preLC[n],sufCT[0]);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='C')
            {
                int l=preL[i+1];
                int t=sufT[i];
                base+=l*t;
            }
            gains=max(gains,(long long)preL[i+1]*sufT[i]);
        }
        return base+gains;
    }
};