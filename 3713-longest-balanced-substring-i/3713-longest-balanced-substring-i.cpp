class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);
            
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                bool flag=true;
                int prev=-1;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]==0) continue;

                    if(prev==-1)
                    {
                        prev=freq[k];
                    }
                    if(freq[k]!=prev)
                    {
                        flag=false;
                    }
                }
                if(flag)
                {
                    maxi=max(j-i+1,maxi);
                }
            }
            
        }
        return maxi;
    }
};