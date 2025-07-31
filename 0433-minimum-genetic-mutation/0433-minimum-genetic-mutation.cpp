class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        set<string>st(bank.begin(),bank.end());
        if(!st.count(endGene))
        {
            return -1;
        }

        queue<string>q;
        unordered_map<string,int>dist;
        q.push(startGene);
        dist[startGene]=0;
        vector<char>chars={'A','C','G','T'};
        while(!q.empty())
        {
            string node=q.front();
            q.pop();

            for(int i=0;i<8;i++)
            {
                string temp=node;
                for(char c:chars)
                {
                    temp[i]=c;
                    if(st.count(temp) && dist.find(temp)==dist.end())
                    {
                        q.push(temp);
                        dist[temp]=dist[node]+1;
                    }
                }
            }
        }
        if(dist.find(endGene)!=dist.end())
        {
            return dist[endGene];
        }
        return -1;
    }
};