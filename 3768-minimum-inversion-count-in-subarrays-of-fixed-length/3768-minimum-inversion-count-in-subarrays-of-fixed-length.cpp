class Solution {
public:
    vector<long long> Tree;

long long getSum(int tl,int tr,int l,int r,int u){
    if(l > r) return 0;
    if(tl == l && tr == r) return Tree[u];

    int m = (tl + tr) / 2;
    return getSum(tl, m, l, min(r, m), 2*u+1) +
           getSum(m+1, tr, max(l, m+1), r, 2*u+2);
}

void update(int tl,int tr,int idx,int val,int u){
    if(idx < tl || idx > tr) return;

    if(tl == tr){
        Tree[u] += val;
        return;
    }
    int m = (tl + tr) / 2;
    update(tl, m, idx, val, 2*u+1);
    update(m+1, tr, idx, val, 2*u+2);
    Tree[u] = Tree[2*u+1] + Tree[2*u+2];
}

long long minInversionCount(vector<int>& nums, int k){
    vector<int> coor = nums;
    sort(coor.begin(), coor.end());
    coor.erase(unique(coor.begin(), coor.end()), coor.end());

    for(int &x : nums)
        x = lower_bound(coor.begin(), coor.end(), x) - coor.begin();

    int n = nums.size(), m = coor.size();
    Tree.assign(4 * m, 0);

    long long inv = 0, ans = LLONG_MAX;

    for(int i = 0;i < n; i++){
        
        // ADD nums[i]
        inv += getSum(0, m-1, nums[i]+1, m-1, 0);
        update(0, m-1, nums[i], +1, 0);

        // Window is full → update answer and REMOVE left element
        if(i >= k-1){
            ans = min(ans, inv);

            int x = nums[i-k+1];

            // Remove x contribution fully (this part was missing in your code!)
            inv -= getSum(0, m-1, 0, x-1, 0);  // x < y pairs it contributed earlier
            update(0, m-1, x, -1, 0);           // remove x itself
        }
    }
    return ans;
}

};