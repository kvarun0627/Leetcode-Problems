class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        int k=edges.size();
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<k;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>Prob(n,0.0);
        Prob[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            auto [prob,curr_node]=pq.top();

            if(curr_node==end_node) return prob;

            pq.pop();

            for(auto [neighbour,n_prob]:adj[curr_node])
            {
                if(Prob[neighbour]<prob*n_prob)
                {
                    pq.push({prob*n_prob,neighbour});
                    Prob[neighbour]=prob*n_prob;
                }
            }
        }
        return Prob[end_node];
    }
};