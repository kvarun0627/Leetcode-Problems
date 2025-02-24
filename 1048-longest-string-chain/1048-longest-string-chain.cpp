class Solution {
public:
    bool check(string&a,string&b)
    {
        int n=a.size();
        int m=b.size();

        if(n!=m+1) return false;

        int first=0;
        int second=0;
        while(first<n)
        {
            if(second<m && a[first]==b[second])
            {
                first++;second++;
            }
            else
            {
                first++;
            }
        }
        return first==n && second==m;
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),[](string a,string b){return a.size()<b.size();});
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
        return maxi;
    }
};