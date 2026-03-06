class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        stack<int>st;
        int n=nums.size();
        int ans = 0;

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
            if(nums[st.top()] != 0)
            {
                ans++;
            }
            st.pop();
        }

        return ans;
    }
};