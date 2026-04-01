class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) 
    {
        int n = positions.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({positions[i],i});
        }

        sort(arr.begin(),arr.end());

        stack<pair<int,int>>st;
        for(int i=0 ; i<n ; i++)
        {
            bool flag = false;
            while(!st.empty() && directions[st.top().second] == 'R' && directions[arr[i].second] == 'L')
            {
                if(health[st.top().second] == health[arr[i].second])
                {
                    st.pop();
                    flag = true;
                    break;
                }
                else if(health[st.top().second] < health[arr[i].second])
                {
                    st.pop();
                    health[arr[i].second]--;
                }
                else
                {
                    health[st.top().second]--;
                    flag = true;
                    break;
                }
            }

            if(!flag && health[arr[i].second] > 0)
            {
                st.push(arr[i]);
            }
        }

        vector<bool>vis(n , false);
        while(!st.empty())
        {
           vis[st.top().second] = true;
           st.pop();
        }

        vector<int>ans;
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i])
            {
                ans.push_back(health[i]);
            }
        }
        return ans;
    }
};