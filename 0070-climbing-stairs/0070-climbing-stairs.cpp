class Solution {
public:
    
    //multiplication of 2 x 2 matrix
    void multiply(vector<vector<int>>&fibMatrix,vector<vector<int>>second) {
        int a=(fibMatrix[0][0]*second[0][0] + fibMatrix[0][1]*second[1][0]);
        int b=(fibMatrix[0][0]*second[0][1] + fibMatrix[0][1]*second[1][1]);
        int c=(fibMatrix[1][0]*second[0][0] + fibMatrix[1][1]*second[1][0]);
        int d=(fibMatrix[1][0]*second[0][1] + fibMatrix[1][1]*second[1][1]);

        fibMatrix[0][0]=a;
        fibMatrix[0][1]=b;
        fibMatrix[1][0]=c;
        fibMatrix[1][1]=d;
    }

    //raise the matrix to the power 'n'
    void power(vector<vector<int>>&fibMatrix, int n) {
        if (n==0 || n==1) return;

        power(fibMatrix,n/2);//recursively divide the power
        multiply(fibMatrix,fibMatrix);//square the matrix
        
        if(n%2!=0)//if n is odd, multiply once more
        {
            vector<vector<int>>baseMatrix={{1,1},{1,0}};
            multiply(fibMatrix,baseMatrix);
        }   
    }

    int climbStairs(int n) {
        if (n==0) return 1;
        vector<vector<int>>fibMatrix={{1,1},{1,0}};
        power(fibMatrix,n);

        return fibMatrix[0][0];
    }
};