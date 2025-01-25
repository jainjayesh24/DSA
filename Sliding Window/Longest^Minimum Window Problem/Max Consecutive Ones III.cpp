//Brute
//TC -> O(N2)
//SC -> O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int n = nums.size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
          int zeros = 0;
          for(int j = i;j<n;j++){
            if(nums[j]==0) zeros++;
            if(zeros<=k) maxi = max(maxi,j-i+1);
            else break;
          }
        }
        return maxi;
    }
};

//Better
// Time Complexity:O(n) - The algorithm involves a single while loop traversing the array with a nested while loop that processes certain elements, both loops combined make it linear in terms of n, which is the size of the input.
// Space Complexity:O(1) - The space used is constant as we are only using a fixed number of variables to store the state and do not require additional space related to the input size.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int n = nums.size();
        int maxi = 0;
        int zeros = 0;
        int l = 0; int r = 0;
        while(r<n){
          if(nums[r]==0) zeros++;
          while(zeros>k){
            if(nums[l]==0) zeros--;
            l++;
          }
          if(zeros<=k) maxi = max(maxi,r-l+1);
          r++;
        }
        return maxi;
    }
};

//Optimal
// Time Complexity:The time complexity of the code is O(n) because it iterates through the nums array once with two pointers.
// Space Complexity:The space complexity of the code is O(1) because it uses a constant amount of extra space.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int n = nums.size();
        int maxi = 0;
        int zeros = 0;
        int l = 0; int r = 0;
        while(r<n){
          if(nums[r]==0) zeros++;
          if(zeros>k){
            if(nums[l]==0) zeros--;
            l++;
          }
          if(zeros<=k) maxi = max(maxi,r-l+1);
          r++;
        }
        return maxi;
    }
};