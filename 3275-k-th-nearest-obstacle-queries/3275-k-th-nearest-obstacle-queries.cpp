class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) 
    {
        multiset<int>low,high;

        auto balance = [&]()
        {
            if(low.size() > k)
            {
                auto it = prev(low.end());
                high.insert(*it);
                low.erase(it);
            }

            if(low.size() < k && !high.empty())
            {
                auto it = high.begin();
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](int num)
        {
            if(low.empty())
            {
                low.insert(num);
            }
            else if(*prev(low.end()) > num)
            {
                low.insert(num);
            }
            else
            {
                high.insert(num);
            }
            balance();
        };

        vector<int>ans;
        for(auto Q:queries)
        {
            add(abs(Q[0])+abs(Q[1]));
            if(low.size() < k)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(*prev(low.end()));
            }
        }

        return ans;
    }
};