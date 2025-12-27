class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        for(int i=n;i>=0;i--)
        {
            int it=lower_bound(citations.begin(),citations.end(),i)-citations.begin();
            int rem=n-it;
            if(rem>=i)
            {
                return i;
            }
        }
        return -1;
    }
};