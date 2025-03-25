class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        while(!pq.empty() && k>1)
        {
            pq.pop();
            k--;
        }
        if(!pq.empty()) return pq.top();
        return -1;
    }
};