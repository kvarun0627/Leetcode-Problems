class Solution {
public:
    vector<string>ans;
    void DFS(string&s , vector<vector<int>>&idx , int u,string str,int n)
    {
        if(u==n)
        {
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int v:idx[u])
        {
            DFS(s,idx,u+v,str+s.substr(u,v)+" ",n);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool>DP(n+1,false);
        DP[n]=true;
        vector<vector<int>>idx(n);
        for(int i=n-1;i>=0;i--)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str+=s[j];
                bool flag=(st.count(str) && DP[j+1]);
                if(flag)
                {
                    idx[i].push_back(j-i+1);
                }
                DP[i]=DP[i] || flag;
            }
        }
        DFS(s,idx,0,"",n);
        return ans;
    }
};