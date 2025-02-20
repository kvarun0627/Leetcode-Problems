class Solution {
public:
    int convert_to_int(string s, int n) {
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += (s[i] == '0' ? 0 : 1) * pow(2, n - i - 1);
        }
        return ans;
    }

    string convert_to_string(int num, int m) {
        string ans = "";
        if (num == 0) {
            return string(m, '0');
        }
        while (num > 0) {
            ans.push_back((num & 1) ? '1' : '0');
            num >>= 1;
        }
        while (ans.length() < m) {
            ans.push_back('0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<int> st;
        for (string s : nums) {
            st.insert(convert_to_int(s, n));
        }
        int max_num = (1 << n) - 1;
        for (int i = 0; i <= max_num; ++i) {
            if (!st.count(i)) {
                return convert_to_string(i, n);
            }
        }
        return "";
    }
};