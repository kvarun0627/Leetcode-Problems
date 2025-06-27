class Solution {
public:
    string convert_string(vector<vector<int>>grid)
    {
        string ans="";
        for(auto ch:grid)
        {
            for(int c:ch)
            {
                ans+=c+'0';
            }
        }
        return ans;
    }
    int get_zero(string s)
    {
        int i=0;
        for(char c:s)
        {
            if(c=='0')
            {
                return i;
            }
            i++;
        }
        return -1;
    }
    vector<pair<int,int>>dir={{0,1},{-1,0},{0,-1},{1,0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        int m=2;
        int n=3;
        queue<pair<string,int>>q;
        string curr=convert_string(board);
        string target=convert_string({{1,2,3},{4,5,0}});

        q.push({curr,0});
        unordered_set<string>st;
        st.insert(curr);
        while(!q.empty())
        {
            auto [node,lvl]=q.front();
            q.pop();
            if(node==target)
            {
                return lvl;
            }
            int idx=get_zero(node);
            int x=idx/n;
            int y=idx%n;

            for(auto [dx,dy]:dir)
            {
                int nx=x+dx;
                int ny=y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    int str_idx=nx*n+ny;
                    swap(node[idx],node[str_idx]);
                    if(!st.count(node))
                    {
                        q.push({node,lvl+1});
                        st.insert(node);
                    }
                    swap(node[idx],node[str_idx]);
                }
            }
        }
        return -1;
    }
};