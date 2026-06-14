class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) 
    {
        for(auto &u : units)
        {
            sort(u.begin(),u.end());
        }
        
        int m = units.size();
        long long sum = 0;

        int mini = INT_MAX;
        int sec_mini = INT_MAX;

        for(int i = 0 ; i<m ; i++)
        {
            if(units[i].size() == 1)
            {
                sum += units[i][0];
                mini = min(mini , units[i][0]);
            }
            else
            {
                sum += units[i][1];
                mini = min(mini , units[i][0]);
                sec_mini = min(sec_mini , units[i][1]);
            }
        }
        
        if(sec_mini == INT_MAX)
        {
            return sum;
        }

        return sum - sec_mini + mini;
    }
};