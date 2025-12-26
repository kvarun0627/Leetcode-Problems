class Solution {
public:
    typedef tuple<double,int,int,int> tp;
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) 
    {
        int Mask=(1 << n) - 1;

        vector<int> bestTime(1 << n, 0);
        for (int mask = 1; mask <= Mask; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bestTime[mask] = max(bestTime[mask], time[i]);
                }
            }
        }

        // dist[base_camp_mask][stage][side]
        const double INF = 1e18;
        vector<vector<vector<double>>> dist(Mask+1, vector<vector<double>>(m, vector<double>(2, INF)));

        priority_queue<tp,vector<tp>,greater<tp>> pq;

        //everyone at base camp, stage=0, boat at base camp
        dist[Mask][0][0] = 0;

        //{curr_time,no.of.peoples_in_camp,curr_stage,curr_side}
        pq.push({0, Mask, 0, 0});

        while (!pq.empty()) 
        {
            auto [curr_time, mask, stage, side] = pq.top();
            pq.pop();

            // if (curr_time > dist[mask][stage][side]) continue;

            // finished
            if (mask == 0 && side == 1) return curr_time;

            if (side == 0) 
            {
                // boat at base camp --> send group
                for (int g = mask; g > 0; g = (g - 1) & mask) 
                {
                    if (__builtin_popcount(g) > k) continue;
                    int maxt = bestTime[g];

                    double d = maxt * mul[stage];//duration
                    int ns = (stage + (int)floor(d + 1e-9)) % m;//next_stage
                    int nmask = mask & ~g;//new_mask
                    double rt = curr_time + d;//reach_time

                    if (dist[nmask][ns][1] > rt) 
                    {
                        dist[nmask][ns][1] = rt;
                        pq.push({rt, nmask, ns, 1});
                    }
                }
            } else 
            {
                // boat at destination one person needs to returns.
                if (mask == Mask) continue;

                int bay = Mask ^ mask;// peoples in the bay
                for (int i = 0; i < n; i++) 
                {
                    if (bay & (1 << i)) 
                    {
                        double d = time[i] * mul[stage];//duration
                        int ns = (stage + (int)floor(d + 1e-9)) % m;//next_stage
                        int nmask = mask | (1 << i);//new_mask
                        double rt = curr_time + d;

                        if (dist[nmask][ns][0] > rt) {
                            dist[nmask][ns][0] = rt;
                            pq.push({rt, nmask, ns, 0});
                        }
                    }
                }
            }
        }

        return -1;
    }

};