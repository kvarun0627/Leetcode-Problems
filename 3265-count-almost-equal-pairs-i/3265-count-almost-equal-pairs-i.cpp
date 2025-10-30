class Solution {
public:
    bool check(int a,int b)
    {
        string num1=to_string(a);
        int n=num1.size();
        int i=0;
        while(i<n && num1[i]=='0')
        {
            i++;
        }
        num1=num1.substr(i);
        string num2=to_string(b);
        int m=num2.size();
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                string temp=num2;
                swap(temp[i],temp[j]);
                int k=0;
                while(k<m && temp[k]=='0')
                {
                    k++;
                }
                temp=temp.substr(k);
                if(temp==num1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(nums[i],nums[j]) || check(nums[j],nums[i]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};