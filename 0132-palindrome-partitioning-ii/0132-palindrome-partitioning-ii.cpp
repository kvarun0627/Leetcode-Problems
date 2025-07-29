class Solution {
public:
    bool is_palindrome(int first,int last,string&s)
    {
        while(first<last)
        {
            if(s[first]!=s[last])
            {
                return false;
            }
            first++;
            last--;
        }
        return true;
    }
    int memo(int idx,int n,vector<int>&DP,string&s)
    {
        if(idx==n)
        {
            return 0;
        }

        if(DP[idx]!=-1)
        {
            return DP[idx];
        }

        int cost=INT_MAX;
        for(int j=idx;j<n;j++)
        {
            if(is_palindrome(idx,j,s))
            {
                cost=min(cost,1+memo(j+1,n,DP,s));
            }
        }
        return DP[idx]=cost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>DP(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            int cost=INT_MAX;
            for(int j=idx;j<n;j++)
            {
                if(is_palindrome(idx,j,s))
                {
                    cost=min(cost,1+DP[j+1]);
                }
            }
            DP[idx]=cost;
        }
        return DP[0]-1;
    }
};