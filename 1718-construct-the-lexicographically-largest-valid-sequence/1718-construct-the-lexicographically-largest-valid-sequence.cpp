class Solution {
public:
    bool back_track(int n, vector<bool>& used, vector<int>& ans, int idx) {
    if (idx == ans.size()) { // Correct base case: check entire sequence length
        return true;
    }
    if (ans[idx] != 0) {
        return back_track(n, used, ans, idx + 1);
    }
    for (int i = n; i >= 1; --i) {
        if (used[i]) continue;
        if (i == 1) { // Handle 1 separately (place once)
            ans[idx] = i;
            used[i] = true;
            if (back_track(n, used, ans, idx + 1)) {
                return true;
            }
            used[i] = false;
            ans[idx] = 0;
        } else { // Handle other numbers (place twice with distance i)
            int nxt_idx = idx + i;
            if (nxt_idx >= ans.size() || ans[nxt_idx] != 0) continue;
            ans[idx] = ans[nxt_idx] = i;
            used[i] = true;
            if (back_track(n, used, ans, idx + 1)) {
                return true;
            }
            ans[idx] = ans[nxt_idx] = 0;
            used[i] = false;
        }
    }
    return false;
}

vector<int> constructDistancedSequence(int n) {
    vector<int> ans(2 * n - 1, 0);
    vector<bool> used(n + 1, false);
    back_track(n, used, ans, 0);
    return ans;
}
};