class Solution {
public:
    typedef pair<int,string> pa;

    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        sort(words.begin(),words.end());

        auto cmp = [](const pa& a, const pa& b)
        {
            if (a.first != b.first)
                return a.first < b.first;   // lower freq → lower priority
            return a.second > b.second;     // lexicographically larger → lower priority
        };


        vector<pair<int,string>>vec;
        int n=words.size();
        vec.push_back({1,words[0]});

        for(int i=1;i<n;i++)
        {
            if(words[i] == vec.back().second)
            {
                vec.back().first++;
            }
            else
            {
                vec.push_back({1,words[i]});
            }
        }

        priority_queue<pa,vector<pa>,decltype(cmp)>pq(cmp);

        for(auto pa:vec)
        {
            pq.push(pa);
        }

        vector<string>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};