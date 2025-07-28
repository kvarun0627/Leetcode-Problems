class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        //here stack.top() always stores the last index where last invalid parantheses has occured.

        st.push(-1);
        int n=s.size();
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(st.top()==-1 || s[st.top()]==')')
                {
                    st.push(i);
                }
                if(s[st.top()]=='(')
                {
                    st.pop();
                    maxLen=max(maxLen,i-st.top());
                }
            }
        }
        return maxLen;
    }
};