class Solution {
public:
    
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end(),greater<int>());

        auto pos=[&](long long val)
        {
            int low=0;
            int high=m-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(val*(long long)potions[mid]>=success)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            return low;
        };

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            long long val=spells[i];
            int num=pos(val);
            ans.push_back(num);
        }
        return ans;
    }
};