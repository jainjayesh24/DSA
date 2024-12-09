// Brute
// o(nlogn+n)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        if(nums.size() == 2) return -1;
        sort(nums.begin(),nums.end());
        int l = nums[nums.size()-1];
        int secL = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]!=l){
                secL = nums[i];
                break;
            }
        }
        return secL;
      
    }
};


//Better
//o(2n)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int l = -1;
        int secL = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > l) {
                l = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > secL && nums[i] != l) {
                secL = nums[i];
            }
        }
        return secL;
    }
};


// Optimal
// tc - O(n)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int l = -1;
        int secL = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > l) {
                secL = l;
                l = nums[i];
            } else if (nums[i] > secL && nums[i] != l) {
                secL = nums[i];
            }
        }
        return secL;
    }
};
