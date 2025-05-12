class RangeFreqQuery {
public:
    unordered_map<int,unordered_map<int,int>>mp;
    vector<int>nums;
    int block;
    RangeFreqQuery(vector<int>& arr) {
        nums=arr;
        int n=arr.size();
        block=(int)sqrt((double)n);
        int i=0;
        int idx=0;
        while(i<n)
        {
            unordered_map<int,int>hash;
            for(int j=i;j<min(n,i+block);j++)
            {
                hash[arr[j]]++;
            }
            mp[idx++]=hash;
            i+=block;
        }
    }

    int query(int left, int right, int value) {
        int ans=0;
        int i;
        for(i=left;i<=right && i%block!=0;i++)
        {
            if(nums[i]==value) ans++;
        }

        while(right-i+1>=block)
        {
            int idx=i/block;
            ans+=mp[idx][value];
            i+=block;
        }
        
        for(;i<=right;i++)
        {
            if(nums[i]==value) ans++;
        }
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */