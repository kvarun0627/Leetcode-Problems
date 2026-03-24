class Solution {
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size();
        stack<int>st;
        
        int ans = 0;
       for(int i=0;i<n;i++)
       {
            if(!st.empty() && target[st.top()]>=target[i])
            {
                ans += (target[st.top()]-target[i]);
            }
            while(!st.empty() && target[st.top()] >= target[i])
            {
                st.pop();
            }
            st.push(i);
       } 

       while(!st.empty())
       {
            int x = target[st.top()];
            st.pop();
            int y = (st.empty()?0:target[st.top()]);
            ans += (x-y);
       }

       return ans;
    }
};