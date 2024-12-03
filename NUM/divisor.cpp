//Divisors of a number
//A number which completely divides another number is called it's divisor.

//Brute
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> result;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                result.push_back(i);
            }
        }
        return result;

    }
};

//optimal
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find all 
    divisors of n */
    vector<int> divisors(int n) {
        
        // To store the divisors;
        vector<int> ans;
        
        int sqrtN = sqrt(n);
        
        // Iterate from 1 to sqrtN
        for(int i=1; i <= sqrtN; i++) {
            
            // If a divisor is found
            if(n % i == 0) {
                //Add it to the answer
                ans.push_back(i);
                
                /* Add the counterpart divisor
                 if it's different from i */
                if(i != n / i) {
                    ans.push_back(n/i);
                }
            }
        }
        
        // Sorting the result 
        sort(ans.begin(), ans.end());
        
        // Return the result
        return ans;
    }
};

int main()
{
    int n = 6;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find 
    all divisors of n */
    vector<int> ans = sol.divisors(n);
    
    cout << "The divisors of " << n << " are: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}