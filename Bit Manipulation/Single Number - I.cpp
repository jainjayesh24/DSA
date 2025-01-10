//Brute 
class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        unordered_map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ele = -1;
        for(auto it: mpp){
            if(it.second == 1){
                ele = it.first;
            }
        }
        return ele;
    }
};

//optimal
// Time Complexity:The time complexity of the given code is O(n) because it iterates over the array once.
// Space Complexity:The space complexity of the code is O(1) as it uses a constant amount of extra space regardless of the input size.

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        // Line 4: Suggestion: Add a comment explaining the use of XOR
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

// Line 4: Adding a comment before the loop explaining how XOR works and why it is used here would be beneficial.
// For example: "XOR operation to find the single number as it cancels out numbers appearing in pairs."