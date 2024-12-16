class Solution {
public:
    double solve(double x, int n)
    {
        if(n==0) return 1;

         double half= solve(x , n/2);

         if( n % 2 == 0)//even
         {
            return half*half;
         }
        //  else{
            //odd
            return half*half* x; // one more time
        //  }

    }

    double myPow(double x, int n) {
        
        if(n<0)
        {
            return 1/solve(x,n);
        }
        //
        return solve(x,n);

    }
};