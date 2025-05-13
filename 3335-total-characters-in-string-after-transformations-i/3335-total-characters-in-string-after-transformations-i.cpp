class Solution {
public:
    int mod=1e9+7;
    int reccur(char a,int t,vector<vector<int>>&DP)
    {
        if('z'-a+1>t) return 1;
        int z='z'-a+1;
        if((a=='a' || a=='b') && DP[a-'a'][t]!=-1) return DP[a-'a'][t];
        if(a!='a' && a!='b')
        {
           return (reccur('a',t-z,DP)%mod+reccur('b',t-z,DP)%mod)%mod;
        }
        DP[a-'a'][t]=reccur('a',t-z,DP)%mod;
        DP[a-'a'][t]=(DP[a-'a'][t]+reccur('b',t-z,DP)%mod)%mod;
        return DP[a-'a'][t];
    }
    int lengthAfterTransformations(string s, int t) {
        vector<long long>hash(26,0);
        for(char c:s)
        {
            hash[c-'a']++;
        }
        long long ans=0;
        vector<vector<int>>DP(2,vector<int>(t+1,-1));
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
            {
                long long x=reccur(i+'a',t,DP)%mod;
                ans=(ans+hash[i]*x)%mod;
            }
        }
        return ans;
    }
};