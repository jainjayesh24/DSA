//GCD of two numbers
//Brute
//tc - o(min(n1,n2))
//sc - o(1)
class Solution {
public:
    int GCD(int n1,int n2) {
        int maxi = 0;
        for(int i =1;i<=min(n1,n2);i++){
            if(n1%i==0 && n2%i==0){
                maxi = max(i,maxi);
            }
        }
        return maxi;

    }
};

// better
//tc - o(min(n1,n2))
//sc - o(1)
class Solution {
public:
    int GCD(int n1,int n2) {
        int maxi = 0;
        for(int i =min(n1,n2);i>=1;i--){
            if(n1%i==0 && n2%i==0){
                maxi = max(i,maxi);
            }
        }
        return maxi;

    }
};


//best -> Euclidean's Algorithm
//O(log(min(n1, n2)))
//o(1)
class Solution {
public:
    int GCD(int n1, int n2) {
        while (n1 != 0 && n2 != 0) {
            if (n1 > n2) {
                n1 = n1 % n2;
            } else {
                n2 = n2 % n1;
            }
        }
        return (n1 == 0) ? n2 : n1;
    }
};

