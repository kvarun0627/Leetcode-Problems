class Solution {
public:

    bool operation(int k, vector<int>& nums) {
        int n = nums.size();
        int chunks = n / k;

        int prevMax = -1;

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

            if(mini < prevMax)
            {
                return false;
            }
            prevMax = maxi;
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
