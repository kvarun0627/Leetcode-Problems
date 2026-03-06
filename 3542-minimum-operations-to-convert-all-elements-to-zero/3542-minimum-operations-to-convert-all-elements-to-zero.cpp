class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        stack<int>st;
        int n=nums.size();
        int ans = 0;
        set<int>cnt;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                ans++;
                st.pop();
            }

            if(!st.empty() && nums[st.top()]==nums[i])
            {
                st.pop();
            }
            
            st.push(i);
        }

        while(!st.empty())
        {
            cnt.insert(nums[st.top()]);
            st.pop();
        }
        ans += (cnt.size() - cnt.count(0));

        return ans;
    }
};