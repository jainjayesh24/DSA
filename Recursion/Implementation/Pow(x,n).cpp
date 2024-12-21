//Brute
class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        if(n<0){
            x = 1/x;
            n = -1*n;
        }
        double ans = 1;
        for(int i = 0;i<n;i++){
            ans = ans*x;
        }
        return ans;
    }
};

//optimal-> iterative code
class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        long num = n;
        double ans = 1;
        if(num<0){
            x = 1/x;
            num = -1*num;
        }
        while(num>0){
            if(num%2){
                ans = ans *x;
                num = num-1;
            }
            else{
                x =x*x;
                num = num/2;
            }
        }
        return ans;
    }
};

//optimal recursive code
// Time Complexity:O(log n) because the function reduces the problem size by half each recursive call when n is even, and by one when n is odd.
// Space Complexity:O(log n) due to the recursion stack space used in the recursive calls.


class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        if(n<0){
            x = 1/x;
            n = -n;
        }
        if(n==0) return 1;
        if(n%2==1){
            return x*myPow(x,n-1);
        }
        return myPow(x*x,n/2);
    }
};