class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:nums)
        {
            pq.push(x);
        }
        int ope=0;
        while(pq.size()>=2 && pq.top()<k)
        {
            int m=pq.top();
            pq.pop();
            int n=pq.top();
            pq.pop();
            pq.push(2*m+n);
            ope++;
        }
        return ope;
    }
};