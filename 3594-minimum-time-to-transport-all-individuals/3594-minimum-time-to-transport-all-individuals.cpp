class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) 
    {
        int FULL = (1 << n) - 1;

        vector<int> bestTime(1 << n, 0);
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bestTime[mask] = max(bestTime[mask], time[i]);
                }
            }
        }

        // dist[mask][stage][side]
        const double INF = 1e18;
        vector<vector<vector<double>>> dist(
            1 << n, vector<vector<double>>(m, vector<double>(2, INF))
        );

        priority_queue<tuple<double,int,int,int>,
                    vector<tuple<double,int,int,int>>,
                    greater<>> pq;

        // start: everyone at base camp, stage=0, boat at base camp
        dist[FULL][0][0] = 0;
        pq.push({0, FULL, 0, 0});

        while (!pq.empty()) {
            auto [curr_time, mask, stage, side] = pq.top();
            pq.pop();

            if (curr_time > dist[mask][stage][side]) continue;

            // finished
            if (mask == 0 && side == 1) return curr_time;

            if (side == 0) {
                // boat at base camp → send group
                for (int g = mask; g > 0; g = (g - 1) & mask) {
                    if (__builtin_popcount(g) > k) continue;
                    int maxt = bestTime[g];
                    if (maxt == 0) continue;

                    double d = maxt * mul[stage];
                    int ns = (stage + (int)floor(d + 1e-9)) % m;
                    int nmask = mask & ~g;
                    double nt = curr_time + d;

                    if (dist[nmask][ns][1] > nt) {
                        dist[nmask][ns][1] = nt;
                        pq.push({nt, nmask, ns, 1});
                    }
                }
            } else {
                // boat at destination → one person returns
                if (mask == FULL) continue;

                int bay = FULL ^ mask;
                for (int i = 0; i < n; i++) {
                    if (bay & (1 << i)) {
                        double d = time[i] * mul[stage];
                        int ns = (stage + (int)floor(d + 1e-9)) % m;
                        int nmask = mask | (1 << i);
                        double nt = curr_time + d;

                        if (dist[nmask][ns][0] > nt) {
                            dist[nmask][ns][0] = nt;
                            pq.push({nt, nmask, ns, 0});
                        }
                    }
                }
            }
        }

        return -1;
    }

};