class Solution {
public:
  
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> st_pair;
    
    for (int i = 0; i < n; i++) {
        st_pair.push_back({nums1[i], i});
    }
    
    sort(st_pair.begin(), st_pair.end(), compare);
    
    vector<long long> ans(n, 0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int pq_size = 0;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        int idx = st_pair[i].second;
        
        if(i>0 && st_pair[i].first==st_pair[i-1].first)
        {
            int prev_idx=st_pair[i-1].second;
            ans[idx]=ans[prev_idx];
            continue;
        }
        if (i > 0) {
            int prev_idx=st_pair[i-1].second;
            pq.push(nums2[st_pair[i-1].second]);
            pq_size++;
            sum += nums2[st_pair[i-1].second];
            
            if (pq_size > k) {
                sum -= pq.top();
                pq.pop();
                pq_size--;
            }
        }
        
        ans[idx] = sum;
    }
    
    return ans;
}

};