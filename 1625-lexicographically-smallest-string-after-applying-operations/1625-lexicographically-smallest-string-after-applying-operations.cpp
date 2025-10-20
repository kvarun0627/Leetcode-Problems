class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        string ans=s;
        queue<string>q;
        set<string>st;
        q.push(s);
        st.insert(s);
        while(!q.empty())
        {
            string node=q.front();
            ans=min(ans,node);
            q.pop();
            string temp=node;
            string temp1=node;
            for(int i=0;i<n;i++)
            {
                if(i & 1)
                {
                    temp[i]=(char)((temp[i]-'0'+a)%10+'0');
                }
            }
            temp1=node.substr(n-b)+node.substr(0,n-b);
            if(!st.count(temp))
            {
                st.insert(temp);
                q.push(temp);
            }
            if(!st.count(temp1))
            {
                st.insert(temp1);
                q.push(temp1);
            }
        }
        return ans;
    }
};