class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum=0;
        map<int,int>mp;
        int n=nums.size();

        for(int x:nums)
        {
            sum+=x;
            mp[x]++;
        }
        int outlier=INT_MIN;

        //assume a number as an outlier and subtract it from array sum and if that subtacted sum is divisible by two check whether (subtracted sum)/2 i.e special number exist are not if so then our assumption is correct
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]--;//reducing the frequency of outlier not to confuse it with special number
            int remaining_sum=sum-nums[i];
            int special_number=remaining_sum/2;
            if((remaining_sum)%2==0 && mp.find(special_number)!=mp.end() && mp[special_number]>0)
            {
                outlier=max(outlier,nums[i]);
            }
            mp[nums[i]]++;
        }
        return outlier;

    }
};