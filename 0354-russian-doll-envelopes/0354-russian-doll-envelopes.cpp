class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto comp=[&](vector<int>&a,vector<int>&b)
        {
            if(a[0]==b[0])
            {
                return a[1]>b[1];
            }
            return a[0]<b[0];
        };

        sort(envelopes.begin(),envelopes.end(),comp);
        
        int n=envelopes.size();
        vector<int>temp;
        int len=0;
        for(int i=0;i<n;i++)
        {
            int ele=envelopes[i][1];
            if(temp.empty() || temp.back()<ele)
            {
                temp.push_back(ele);
                len++;
            }
            else
            {
                int idx=lower_bound(temp.begin(),temp.end(),ele)-temp.begin();
                temp[idx]=ele;
            }
        }
        return len;
    }
};