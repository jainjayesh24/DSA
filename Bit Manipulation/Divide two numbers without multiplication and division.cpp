class Solution {
public:
    int divide(int dividend, int divisor) {
        //your code goes here
        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false;
        if(dividend<0 && divisor) sign = false;

        int n = abs(dividend);
        int d = abs(divisor);
        
        int ans = 0;
        while(n>=d){
            int count = 0;
            while( n >= (d<<count+1)){
                count++;
            }
            ans = ans + (1<<count);
            n = n - d*(1<<count);
        }

        if(ans > INT_MAX && sign == true) return INT_MAX;
        else if(ans>INT_MAX && sign == false ) return INT_MIN;

        if(sign == true) return ans;
        else return (-1)*ans;
    }
};