class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int x:nums)
        {
            pq.push(x);
        }
        long long score=0;
        while(!pq.empty() && k)
        {
            int n=pq.top();
            score+=n;
            pq.pop();
            pq.push((int)ceil(n/3.0));
            k--;
        }
        return score;
    }
};