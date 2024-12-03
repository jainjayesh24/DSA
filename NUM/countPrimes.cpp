//Count of prime numbers till N
// You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range
// A prime number is a number which has no divisors except, 1 and itself.4


class Solution {
private:
bool isPrime(int n){
    if (n==1) return false;
    for(int i = 2; i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
public:
    int primeUptoN(int n) {
        int count =0;
        for(int i = 1; i<=n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }
};