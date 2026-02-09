class Solution {
public:
    vector<vector<int>>Tree;
    void build(int u, int l,int r, vector<int>&nums)
    {
        if(l==r)
        {
            Tree[u] = {nums[l]};
            return ;
        }

        int mid = (l+r)/2;
        build(2*u+1,l,mid,nums);
        build(2*u+2,mid+1,r,nums);
        Tree[u].resize(Tree[2*u+1].size() + Tree[2*u+2].size());
        merge(Tree[2*u+1].begin(),Tree[2*u+1].end(),Tree[2*u+2].begin(),Tree[2*u+2].end(),Tree[u].begin());
    } 
    int get(int u,int l,int r,int tl,int tr,int x)
    {
        if(tl>tr)
        {
            return 0;
        }
        if(tl==l && tr==r)
        {
            return upper_bound(Tree[u].begin(),Tree[u].end(),x-1) - Tree[u].begin();
        }
        int mid=(l+r)/2;
        int left = get(2*u+1,l,mid,tl,min(tr,mid),x);
        int right = get(2*u+2,mid+1,r,max(tl,mid+1),tr,x);
        return left+right;
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        Tree.resize(4*n);
        build(0,0,n-1,nums);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(get(0,0,n-1,i+1,n-1,nums[i]));
        }
        return ans;
    }
};