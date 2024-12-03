//LCM of two Numbers

//Brute
// tc -> o(n1*n2)
//sc -> o(1)
class Solution {
public:
    int LCM(int n1,int n2) {
        int i = 1;
        int maxi = max(n1,n2);
        do{
            int mult = i * maxi;
            if(mult%n1 == 0 && mult%n2 == 0) return mult;
            i +=1;
        }
        while(1);
    }
};

//optimal