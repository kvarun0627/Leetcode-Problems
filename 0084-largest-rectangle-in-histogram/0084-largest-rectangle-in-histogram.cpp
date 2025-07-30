class Solution {
public:
    vector<int>NextSmallestElement(vector<int>& heights,int n)
    {
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(heights[st.top()]<heights[i])
            {
                nse[i]=st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    nse[i]=st.top();
                }
                st.push(i);
            }
            
        }
        return nse;
    }
    vector<int>PreviousSmallerElement(vector<int>& heights,int n)
    {
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(heights[st.top()]<heights[i])
            {
                pse[i]=st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    pse[i]=st.top();
                }
                st.push(i);
            }
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        //the brute force is simple
        //for every i the area that can be obtained will be arr[i]*(nse[i]-pse[i]-1);
        int n=heights.size();
        vector<int>nse=NextSmallestElement(heights,n);
        vector<int>pse=PreviousSmallerElement(heights,n);

        int maxi=0;

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }

        return maxi;

    }
};