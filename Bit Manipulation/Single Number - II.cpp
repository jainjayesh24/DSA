//Brute --> Hashmap

//Better-I
// Time Complexity:The time complexity of the given code is O(n log n) due to the sort operation, followed by an O(n/3) loop.
// Space Complexity:The space complexity is O(1) if we ignore the space used by the sort function, as no additional data structures are used.

class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        //your code goes here
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i+=3){
            if(nums[i-1]!=nums[i]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
