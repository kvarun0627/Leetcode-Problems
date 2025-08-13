class Solution {
public:
    int count(int X,int n,vector<int>&arr)
    {
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(arr[i]-arr[j]>X)
            {
                j++;
            }
            cnt=cnt+(i-j);
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int cnt=count(mid,n,nums);
            // cout<<"For "<<mid<<" I got "<<cnt<<" as the count "<<endl;
            if(cnt>=k)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};