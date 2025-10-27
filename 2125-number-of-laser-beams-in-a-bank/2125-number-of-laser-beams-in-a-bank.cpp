class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int ans=0;
        int prev=-1;
        for(int i=0;i<m;i++)
        {
            int one=0;
            for(char c:bank[i])
            {
                one+=c-'0';
            }
            if(prev==-1)
            {
                prev=one;
            }
            else if(one!=0)
            {
                ans+=one*prev;
                prev=one;
            }
        }
        return ans;
    }
};