class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int maxi=0;
        auto it=nums.begin()+1;
        while(it!=nums.end())
        {
            maxi=max(maxi,*it-*(it-1));
            it++;
        }
        return maxi;
    }
};