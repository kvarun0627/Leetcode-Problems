class Solution {
public:
   bool sum_of_subnum(int num,int k) {
    if (k<0 || num<k){
        return false;
    }
    if(num==k)
    {
        return true;
    }

    return sum_of_subnum(num/10,k-num%10) || sum_of_subnum(num/100,k-num%100) || sum_of_subnum(num/1000,k-num%1000);
}

int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sum_of_subnum(i*i,i)){
            ans += i * i;
        }
    }
    return ans;
}
};