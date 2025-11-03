class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        auto cmp=[&](int a,int b)
        {
            return abs(a)<abs(b);
        };
        sort(nums.begin(),nums.end(),cmp);
        long long maxi=-1e15;
        int n=nums.size();
        long long large=nums[n-1];
        long long second_large=nums[n-2];
        return max(-1LL*large*second_large*1e5,large*second_large*1e5);

    }
};