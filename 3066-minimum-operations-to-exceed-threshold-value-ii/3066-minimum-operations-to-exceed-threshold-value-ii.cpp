class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int x:nums)
        {
            pq.push(x);
        }
        int ope=0;
        while(pq.size()>=2 && pq.top()<k)
        {
            long long m=pq.top();
            pq.pop();
            long long n=pq.top();
            pq.pop();
            pq.push(2*m+n);
            ope++;
        }
        return ope;
    }
};