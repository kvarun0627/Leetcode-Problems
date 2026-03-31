

    /*
Observations:

- For all k such that k divides n:
    1. Divide array into chunks of size k
    2. Each chunk must be rotated sorted:
        -> At most 1 inversion
    3. Maintain (min, max) for each chunk
    4. Ensure global ordering:
        max[i] <= min[i+1]

TC:
- Divisors: O(sqrt(n))
- Each check: O(n)
=> Overall: O(n * sqrt(n))

SC:
- O(n/k) for storing chunk min/max
*/

class Solution {
public:

    bool operation(int k, vector<int>& nums) {
        int n = nums.size();
        int chunks = n / k;

        vector<pair<int, int>> minMax(chunks);

        for (int i = 0; i < chunks; i++) {
            int start = i * k;

            int mini = INT_MAX;
            int maxi = INT_MIN;
            int cnt = 0;

            for (int j = 0; j < k; j++) {
                int curr = nums[start + j];
                int next = nums[start + (j + 1) % k];

                mini = min(mini, curr);
                maxi = max(maxi, curr);

                if (curr > next) cnt++;
            }

            if (cnt > 1) return false; // not rotated sorted

            minMax[i] = {mini, maxi};
        }

        // global ordering check
        for (int i = 0; i < chunks - 1; i++) {
            if (minMax[i].second > minMax[i + 1].first) {
                return false;
            }
        }

        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (operation(i, nums)) ans += i;

                if (i != n / i) {
                    if (operation(n / i, nums)) ans += (n / i);
                }
            }
        }

        return ans;
    }
};
