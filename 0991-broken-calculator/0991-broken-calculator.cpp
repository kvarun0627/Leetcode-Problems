class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startvValue)
        {
            ans++;
            if(target & 1)
            {
                target++;
            }
            else
            {
                target=target/2;
            }
        }
        return ans+startValue-target;
    }
};