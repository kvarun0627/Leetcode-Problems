class Solution {
public:
    int flip_digit=0^1;
    void flip(vector<int>&dup,int idx)
    {
        dup[idx]^=flip_digit;
        dup[idx+1]^=flip_digit;
        dup[idx+2]^=flip_digit;
    }
    int minOperations(vector<int>& nums) {
        vector<int>dup=nums;
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n-2;i++)
        {
            if(dup[i]==0)
            {
                flip(dup,i);
                ops++;
            }
        }
        return (dup[n-2]==1 && dup[n-1]==1)?ops:-1;
    }
};