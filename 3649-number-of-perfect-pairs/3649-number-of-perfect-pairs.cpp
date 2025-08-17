class Solution {
public:
    //from the given mathematical expression max(|x|,|y|)<=2*min(|x|,|y|)
    //replace evry value to their absolute value ans sort them
    long long perfectPairs(vector<int>& nums) {
        vector<int>arr;
        for(int num:nums)
        {
            arr.push_back(abs(num));
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int j=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            while(j<i && arr[i]>2*arr[j])
            {
                j++;
            }
            ans+=(i-j);
        }
        return ans;
    }
};