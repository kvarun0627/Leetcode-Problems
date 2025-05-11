class Solution {
public:
    int minDeletion(string s, int k) {
        set<char>st(s.begin(),s.end());
        int dis=st.size();
        if(dis<=k) return 0;
        vector<int>hash(26,0);
        for(int c:s)
            {
                hash[c-'a']++;
            }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int I:hash)
            {
                if(I)
                {
                    pq.push(I);
                }
            }
        int d=dis-k;
        int ops=0;
        while(d>0 && !pq.empty())
            {
                ops+=pq.top();
                pq.pop();
                d--;
            }
        if(d>0) return 0;

            return ops;
    }
};