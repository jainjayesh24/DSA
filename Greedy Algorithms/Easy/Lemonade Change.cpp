// Time Complexity:O(n) because the algorithm iterates over the bills array once, performing constant-time operations for each bill
// Space Complexity:O(1) as the algorithm uses a fixed amount of extra space regardless of the input size, with only a few integer variables for tracking changes.
class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
        //your code goes here
        int f = 0;
        int t = 0;
        int n = bills.size();
        for(int i = 0; i<n;i++){
            if(bills[i]==5){
                f++;
            }
            else if(bills[i]==10){
                if(f){
                    f--;
                    t++;
                }
                else return false;
            }else{
                if(f && t){
                    f--;
                    t--;
                }else if(f>=3) f = f-3;
                else return false;
            }
        }
        return true;
    }
};