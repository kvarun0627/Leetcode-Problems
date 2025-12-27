class MajorityChecker {
public:
    typedef pair<int,int> pa;
    vector<pa>tree;
    int N;
    pa merge(pa&a,pa&b)
    {
        int c1=a.first;
        int c2=b.first;
        int f1=a.second;
        int f2=b.second;
        if(c1==-1 && c2==-1)
        {
            return {-1,0};
        }
        else if(c1==-1)
        {
            return {c2,f2};
        }
        else if(c2==-11)
        {
            return {c1,f1};
        }
        else if(c1==c2)
        {
            return {c1,f1+f2};
        }
        else if(f1==f2)
        {
            return {-1,0};
        }
        else if(f1>f2)
        {
            return {c1,f1-f2};
        }
        return {c2,f2-f1};
    }
    void build(int l,int r,int u,vector<int>&arr)
    {
        if(l==r)
        {
            tree[u]={arr[l],1};
            return ;
        }
        int m=(l+r)/2;
        build(l,m,2*u+1,arr);
        build(m+1,r,2*u+2,arr);
        tree[u] = merge(tree[2*u+1],tree[2*u+2]);
    }
    pa range(int ql,int qr,int l,int r,int u)
    {
        if(ql>qr)
        {
            return {-1,0};
        }
        if(ql==l && qr==r)
        {
            return tree[u];
        }
        int m=(l+r)/2;
        pa left=range(ql,min(qr,m),l,m,2*u+1);
        pa right=range(max(m+1,ql),qr,m+1,r,2*u+2);
        return merge(left,right);
    }
    unordered_map<int,vector<int>>mp;
    MajorityChecker(vector<int>& arr) 
    {
        int n=arr.size();
        N=n;
        tree.resize(4*n);
        build(0,n-1,0,arr);
        int j=0;
        for(int i:arr)
        {
            mp[i].push_back(j);
            j++;
        }
    }
    int query(int left, int right, int threshold) 
    {
        pa node=range(left,right,0,N-1,0);
        int ele=node.first;
        auto&Idx=mp[ele];
        int l=lower_bound(Idx.begin(),Idx.end(),left)-Idx.begin();
        int r=upper_bound(Idx.begin(),Idx.end(),right)-Idx.begin();
        if(r-l>=threshold)
        {
            return ele;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */