//Check for perfect number

// You are given an integer n. You need to check if the number is a perfect number or not. Return true if it is a perfect number, otherwise, return false.
// A perfect number is a number whose proper divisors add up to the number itself.


// Brute
class Solution {
public:
    bool isPerfect(int n) {
        int sum = 0;
        for(int i = 1;i<n;i++){
            if(n%i == 0){
                sum +=i;
            }
        }
        return sum == n;

    }
};


// optimal
class Solution {
public:
    bool isPerfect(int n) {
        int sum = 0;
        if(n==1) return false;
        int N = sqrt(n);
        for(int i= 1;i<=N;i++){
            if(n%i==0){
                sum +=i;
                if((n/i)!=n && (n/i)!=i){
                    sum += n/i;
                }
            }
        }
        return sum == n;
    }
};

