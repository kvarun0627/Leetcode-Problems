class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        if(m>n)
        {
            return findMedianSortedArrays(nums2,nums1);
        }

        int tot=m+n;
        int half=(m+n+1)/2;

        int low=0;//to include zero elements into the first half
        int high=m;//to include all the elements into the first half
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=half-mid1;

            int num1_left=mid1-1>=0?nums1[mid1-1]:INT_MIN;
            int num1_right=mid1<m?nums1[mid1]:INT_MAX;
            int num2_left=mid2-1>=0?nums2[mid2-1]:INT_MIN;
            int num2_right=mid2<n?nums2[mid2]:INT_MAX;

            if(num1_left>num2_right)
            {
                high=mid1-1;
            }
            else if(num1_right<num2_left)
            {
                low=mid1+1;
            }
            else
            {
                if(tot & 1)
                {
                    return max(num1_left,num2_left);
                }
                else
                {
                    return (double)(max(num1_left,num2_left)+min(num1_right,num2_right))/2;
                }
            }
        }
        return -1.0;
    }
};