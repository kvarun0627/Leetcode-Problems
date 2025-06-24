class Solution {
public:
    bool is_valid(string&str)
    {
        stack<char>st;
        for (char ch:str)
        {
            if (ch>='a' && ch<='z')
                continue;

            if (ch=='(')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                if (st.empty() || st.top()!='(')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }

    void BFS(string&s,vector<vector<string>>&dist)
    {
        queue<pair<string,int>>q;
        q.push({s,0});
        unordered_set<string>vis;
        vis.insert(s);
        while(!q.empty())
        {
            auto [str,lvl]=q.front();
            q.pop();
            if(is_valid(str))
            {
                dist[lvl].push_back(str);
            }
            int k=str.size();
            for(int i=0;i<k;i++)
            {
                if(str[i]>='a' && str[i]<='z')
                {
                    continue;
                }
                string nxt=str.substr(0,i)+str.substr(i+1);
                if(!vis.count(nxt))
                {
                    q.push({nxt,lvl+1});
                    vis.insert(nxt);
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        vector<vector<string>>dist(n+1);
        vector<string>ans;
        BFS(s,dist);
        for(int i=0;i<n;i++)
        {
            if(!dist[i].empty())
            {
                return dist[i];
            }
        }
        return {""};
    }
};