class Solution {
public:
    // vector<int>NextSmallestElement(vector<int>& heights,int n)
    // {
    //     vector<int>nse(n,n);
    //     stack<int>st;
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(i);
    //         }
    //         else if(heights[st.top()]<heights[i])
    //         {
    //             nse[i]=st.top();
    //             st.push(i);
    //         }
    //         else
    //         {
    //             while(!st.empty() && heights[st.top()]>=heights[i])
    //             {
    //                 st.pop();
    //             }
    //             if(!st.empty())
    //             {
    //                 nse[i]=st.top();
    //             }
    //             st.push(i);
    //         }
            
    //     }
    //     return nse;
    // }
    // vector<int>PreviousSmallerElement(vector<int>& heights,int n)
    // {
    //     vector<int>pse(n,-1);
    //     stack<int>st;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(i);
    //         }
    //         else if(heights[st.top()]<heights[i])
    //         {
    //             pse[i]=st.top();
    //             st.push(i);
    //         }
    //         else
    //         {
    //             while(!st.empty() && heights[st.top()]>=heights[i])
    //             {
    //                 st.pop();
    //             }
    //             if(!st.empty())
    //             {
    //                 pse[i]=st.top();
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return pse;
    // }
    int largestRectangleArea(vector<int>& heights) {
        //the brute force is simple
        //for every i the area that can be obtained will be arr[i]*(nse[i]-pse[i]-1);

        //T.C will be around O(5N) and S.C will be around O(4N)

        // int n=heights.size();
        // vector<int>nse=NextSmallestElement(heights,n);
        // vector<int>pse=PreviousSmallerElement(heights,n);

        // int maxi=0;

        // for(int i=0;i<n;i++)
        // {
        //     maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        // }

        // return maxi;

        //optimal
        //in the most optimal approach we will try to do it in a single iteration

        int n=heights.size();
        stack<int>pse;

        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(pse.empty() || heights[pse.top()]<=heights[i])
            {
                pse.push(i);
            }
            else
            {
                while(!pse.empty() && heights[pse.top()]>heights[i])
                {
                    int h=heights[pse.top()];
                    pse.pop();
                    int pse_idx=pse.empty()?-1:pse.top();
                    int nse_idx=i;
                    maxi=max(maxi,h*(nse_idx-pse_idx-1));
                }
                pse.push(i);
            }
        }

        while(!pse.empty())
        {
            int nse_idx=n;
            int h=heights[pse.top()];
            pse.pop();
            int pse_idx=pse.empty()?-1:pse.top();
            maxi=max(maxi,h*(nse_idx-pse_idx-1));
        }
        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>pref_mat(m,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    pref_mat[j][i]=matrix[j][i]-'0';
                }
                else
                {
                    if(matrix[j][i]=='0')
                    {
                        pref_mat[j][i]=0;
                    }
                    else
                    {
                        pref_mat[j][i]=pref_mat[j-1][i]+(matrix[j][i]-'0');
                    }
                }
            }
        }

        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<pref_mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans=max(ans,largestRectangleArea(pref_mat[i]));
        }
        return ans;
    }
};