//Brute
// TC ->O(N*3)
// SC ->O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                int sum = 0;
                for(int k = i; k<=j;k++){
                    sum += nums[k];
                    Maxi = max(sum,Maxi);
                }
            }
        }
        return Maxi;
    }
};

//Better
// TC ->O(N*2)
// SC ->O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                Maxi = max(sum,Maxi);
                }
            }
        return Maxi;
    }
};

//Optimal
// TC ->O(N)
//Sc - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
        
    }
};