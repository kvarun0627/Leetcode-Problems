class Solution {
public:
    void slidingWindowMedian(vector<int>& nums, int k, vector<long long>& arr,
                             int n) {
        multiset<int> low, high;
        long long low_sum = 0;
        long long high_sum = 0;

        auto balance = [&]() {
            if (low.size() > high.size() + 1) {
                int x = *low.rbegin();
                auto it = low.find(x);
                low.erase(it);
                high.insert(x);
                low_sum -= x;
                high_sum += x;
            } else if (low.size() < high.size()) {
                int x = *high.begin();
                auto it = high.find(x);
                high.erase(it);
                low.insert(x);
                high_sum -= x;
                low_sum += x;
            }
        };
        auto remove = [&](int x) {
            if (!low.empty() && x <= *low.rbegin()) {
                low.erase(low.find(x));
                low_sum -= x;
            } else {
                high.erase(high.find(x));
                high_sum -= x;
            }
            balance();
        };
        auto add = [&](int x) {
            if (low.empty() || x <= *low.rbegin()) {
                low.insert(x);
                low_sum += x;
            } else {
                high.insert(x);
                high_sum += x;
            }
            balance();
        };
        auto median_cost = [&]() {
            int med = *low.rbegin();
            long long cost = 0;
            cost += 1LL * med * low.size() - low_sum;
            cost += high_sum - 1LL * med * high.size();
            return cost;
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= k - 1) {
                arr.push_back(median_cost());
                remove(nums[i - k + 1]);
            }
        }
    }
    long long memo(int idx, vector<long long>& arr, int k, int m, int x,
                   vector<vector<long long>>& DP) {
        if (k == 0) {
            return 0;
        }

        if (idx >= m) {
            return 1e15;
        }

        if (DP[idx][k] != -1) {
            return DP[idx][k];
        }

        long long skip = memo(idx + 1, arr, k, m, x, DP);
        long long not_skip = arr[idx] + memo(idx + x, arr, k - 1, m, x, DP);
        return DP[idx][k] = min(skip, not_skip);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> arr;
        slidingWindowMedian(nums, x, arr, n);

        int m = n - x + 1;
        vector<vector<long long>> DP(m + 1, vector<long long>(k + 1, -1));
        return memo(0, arr, k, m, x, DP);
    }
};