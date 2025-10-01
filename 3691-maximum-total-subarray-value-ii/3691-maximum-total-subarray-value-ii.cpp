class Solution {
public:
    vector<int>Tree1;
    vector<int>Tree2;
    void build(int u,int tl,int tr,vector<int>&nums)
    {
        if(tl==tr)
        {
            Tree1[u]=nums[tl];
            Tree2[u]=nums[tl];
            return ;
        }
        int tm=(tl+tr)/2;
        build(2*u+1,tl,tm,nums);
        build(2*u+2,tm+1,tr,nums);
        Tree1[u]=min(Tree1[2*u+1],Tree1[2*u+2]);
        Tree2[u]=max(Tree2[2*u+1],Tree2[2*u+2]);
    }
    int mini(int u,int tl,int tr,int l,int r,vector<int>&nums)
    {
        if(l>r)
        {
            return INT_MAX;
        }
        if(tl==l && tr==r)
        {
            return Tree1[u]; 
        }
        int tm=(tl+tr)/2;
        int right=mini(2*u+2,tm+1,tr,max(tm+1,l),r,nums);
        int left=mini(2*u+1,tl,tm,l,min(tm,r),nums);
        return min(right,left);
    }
    int maxi(int u,int tl,int tr,int l,int r,vector<int>&nums)
    {
        if(l>r)
        {
            return INT_MIN;
        }
        if(tl==l && tr==r)
        {
            return Tree2[u]; 
        }
        int tm=(tl+tr)/2;
        int right=maxi(2*u+2,tm+1,tr,max(tm+1,l),r,nums);
        int left=maxi(2*u+1,tl,tm,l,min(tm,r),nums);
        return max(right,left);
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        Tree1.assign(4*n+1,0);
        Tree2.assign(4*n+1,0);
        build(0,0,n-1,nums);

        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        int value=maxi(0,0,n-1,0,n-1,nums)-mini(0,0,n-1,0,n-1,nums);
        pq.push({value,{0,n-1}});
        st.insert({0,n-1});
        long long ans=0;
        while(k--)
        {
            auto [val,coor]=pq.top();
            auto [x,y]=coor;
            ans+=val;
            if(y-1>x && !st.count({x,y-1}))
            {
                int nval=maxi(0,0,n-1,x,y-1,nums)-mini(0,0,n-1,x,y-1,nums);
                pq.push({nval,{x,y-1}});
                st.insert({x,y-1});
            }
            if(x+1<y && !st.count({x+1,y}))
            {
                int nval=maxi(0,0,n-1,x+1,y,nums)-mini(0,0,n-1,x+1,y,nums);
                pq.push({nval,{x+1,y}});
                st.insert({x+1,y});
            }
        }
        return ans;
    }
};