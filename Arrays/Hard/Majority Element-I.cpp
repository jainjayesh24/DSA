//Better
// Time Complexity:O(n) due to iterating through the vector and the map
// Space Complexity:O(n) for storing elements and their frequencies in the map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int n = nums.size()/2;
        int ele = 0,MaxFre = 0;
        for(auto it: mpp){
            int E = it.first;
            int fr = it.second;
            if(fr>=n){
                MaxFre = fr;
                ele = E;
            }
        }
        return ele;
    }
};

// Optimal
// Time Complexity:O(n) due to the two for loops iterating through the array
// Space Complexity:O(1) since only a fixed number of variables are used
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(count==0){
                count = 1;
                ele = nums[i];
            }else if(ele == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        int C = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==ele) C++;
        }
        if(C>(nums.size()/2)) return ele;
        return -1;
    }
};