class Solution {
public:
    int minAllOneMultiple(int k) 
    {
        int rem=1;
        set<int>st;
        int len=1;
        while(rem!=0)
        {
            rem = (rem*10+1)%k;
            if(st.count(rem))
            {
                return -1;
            }
            st.insert(rem);
            len++;
        }
        return len;
    }
};