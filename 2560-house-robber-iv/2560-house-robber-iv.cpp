class Solution {
public:
    // APPROACH-1
    // bool memo(vector<int>& nums, vector<vector<int>>& DP, int k, int mid, int idx, int n) {
    //     if (k == 0) return true;
    //     if (idx >= n) return false;
        
    //     if (DP[idx][k] != -1) return DP[idx][k];

    //     bool take = false;
    //     if (nums[idx] <= mid) {
    //         take = memo(nums, DP, k - 1, mid, idx + 2, n);
    //     }
    //     bool not_take = memo(nums, DP, k, mid, idx + 1, n);

    //     return DP[idx][k] = (take || not_take);
    // }

    // bool house_robber(vector<int>& nums, int k, int mid, int n) {
    //     vector<vector<int>> DP(n, vector<int>(k + 1, -1));
    //     return memo(nums, DP, k, mid, 0, n);
    // }

    // int minCapability(vector<int>& nums, int k) {
    //     int maxi = 0;
    //     int mini = INT_MAX;
    //     int n = nums.size();
    //     for (int x : nums) {
    //         maxi = max(x, maxi);
    //         mini = min(x, mini);
    //     }

    //     int low = mini;
    //     int high = maxi;
    //     while (low <= high) {
    //         int mid = (low + high) / 2;
    //         if (house_robber(nums, k, mid, n)) {
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return low;
    // }
    bool check(vector<int>& nums, int k,int mid, int n)
    {
        int possibletheft=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=mid)
            {
                possibletheft++;
                i++;
            }
        }
        return possibletheft>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int maxi = 0;
        int mini = INT_MAX;
        int n = nums.size();
        for (int x : nums) {
            maxi = max(x, maxi);
            mini = min(x, mini);
        }

        int low = mini;
        int high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, k, mid, n)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

};