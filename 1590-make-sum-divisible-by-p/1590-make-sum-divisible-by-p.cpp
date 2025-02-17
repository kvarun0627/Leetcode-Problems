class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
    long long sum = 0;
    for (int x : nums) {
        sum += x;
    }

    if (sum % k == 0) return 0; // Already divisible

    int req = sum % k;
    unordered_map<int, int> hash; // Store prefix sum mod k and index
    hash[0] = -1; // Important: This handles the case where a prefix itself is the answer.

    long long s1 = 0;
    int ans = nums.size();

    for (int i = 0; i < nums.size(); i++) {
        s1 += nums[i];
        int mod = s1 % k;
        if (mod < 0) mod += k;

        int find = (mod - req + k) % k; // Ensure positive remainder

        if (hash.count(find)) {
            ans = min(ans, i - hash[find]);
        }

        hash[mod] = i; // Update latest index
    }

    return (ans == nums.size()) ? -1 : ans;
}

};