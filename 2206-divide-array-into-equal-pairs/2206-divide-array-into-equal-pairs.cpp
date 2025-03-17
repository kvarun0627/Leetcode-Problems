class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>freq(501,0);
        for(int x:nums)
        {
            freq[x]++;
        }
        
        for(int y:freq)
        {
            if(y & 1) return false;
        }
        return true;
    }
};